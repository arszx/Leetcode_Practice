#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
 
#define LOOP_QUEUE_SIZE               50
 
/*标志，如果定义则启动子线程读循环队列数据*/
#define THREAD_TEST
 
/*循环队列要存储的信息*/
typedef struct {
  uint32_t status;
  uint32_t value;
}info_t;
 
/*循环队列控制结构体*/
typedef struct loop_queue{
  pthread_rwlock_t lock;
  uint32_t size;
  uint32_t rd;
  uint32_t wd;
  info_t info[LOOP_QUEUE_SIZE];
 
  void (*rdlock)(struct loop_queue *);
	void (*wrlock)(struct loop_queue *);
	void (*unlock)(struct loop_queue *);
	void (*loop_write)(struct loop_queue *,info_t *);
	uint32_t (*loop_read)(struct loop_queue *,info_t *);
}loop_queue_t;
 
/*循环队列---多线程读锁*/
void loop_rdlock(loop_queue_t *loop)
{
  pthread_rwlock_rdlock(&loop->lock);
}
 
/*循环队列---多线程写锁*/
void loop_wrlock(loop_queue_t *loop)
{
  pthread_rwlock_wrlock(&loop->lock);
}
 
/*循环队列---多线程解锁*/
void loop_unlock(loop_queue_t *loop)
{
  pthread_rwlock_unlock(&loop->lock);
}
 
/*循环队列---写数据到队列*/
void loop_queue_write(loop_queue_t *loop, info_t *info)
{
  loop->wrlock(loop);
  uint32_t w = loop->wd;
  loop->size ++;
  if (loop->size > LOOP_QUEUE_SIZE) {
    //循环队列满
    loop->size = LOOP_QUEUE_SIZE;
    if (loop->wd == loop->rd) {
      //读指针后移
      loop->rd = ++loop->rd >= LOOP_QUEUE_SIZE ? 0 : loop->rd;
    }
  }
  //写入数据
  loop->info[w].status = info->status;
  loop->info[w].value = info->value;
  loop->wd = ++loop->wd >= LOOP_QUEUE_SIZE ? 0 : loop->wd;
  loop->unlock(loop);
  printf("write: size = %d, wd = %d, rd = %d\r\n", loop->size, loop->wd, loop->rd);
}
 
/*循环队列---从队列读数据*/
uint32_t loop_queue_read(loop_queue_t *loop, info_t *info)
{
  uint32_t r = loop->rd;
  if (loop->rd == loop->wd && loop->size == 0) {
    printf("loop is empty\r\n");
    return 1;
  }
  info->status = loop->info[r].status;
  info->value = loop->info[r].value;
  loop->rd = ++loop->rd >= LOOP_QUEUE_SIZE ? 0 : loop->rd;
  loop->size --;
  printf("read: size = %d, wd = %d, rd = %d\r\n", loop->size, loop->wd, loop->rd);
  return 0;
}
 
/*循环队列初始化*/
void loop_queue_init(loop_queue_t *loop)
{
  pthread_rwlock_init(&loop->lock, NULL);
	loop->size = 0;
	loop->wd = 0;
	loop->rd = 0;
	loop->rdlock = loop_rdlock;
	loop->wrlock = loop_wrlock;
	loop->unlock = loop_unlock;
	loop->loop_write =loop_queue_write;
	loop->loop_read=loop_queue_read;
}
 
 
 
/*子线程，用于测试读取数据*/
void *read_loop_test(void *arg)
{
  loop_queue_t *loop = arg;
  while (1) {
    loop->rdlock(loop);
    info_t info;
    if (0 == loop->loop_read(loop, &info)) {
      printf("status = %d, value = %d\r\n", info.status, info.value);
    }
    loop->unlock(loop);
    sleep(1);
  }
}
 
int main()
{
  pthread_t rs;
  loop_queue_t loop_queue_ctrl;
  loop_queue_init(&loop_queue_ctrl);
  #ifdef THREAD_TEST
  int ret = pthread_create(&rs, NULL, read_loop_test, &loop_queue_ctrl);
  if (0 != ret) {
    printf("create thread failed\r\n");
    return 1;
  }
  #endif
  while (1) {
    uint32_t i,j;
    for (i = 0, j = 200; i < 200; i++, j--) {
      info_t info;
      info.status = i;
      info.value = j;
      loop_queue_ctrl.loop_write(&loop_queue_ctrl, &info);
      usleep(500000);
    }
    sleep(60);
  }
  return 0;
}
