//包含min函数的栈

//m_data是数据栈，m_min是辅助栈
template<typename T> void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);
	
	if(m_min.size()==0 || value<m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template<typename T> void StackWithMin<T>::pop()
{
	assert(m_data.size()>0 && m_min.size()>0);  //assert函数：如果条件判断为假，则打印出错信息，并终止程序执行；
	
	m_data.pop();
	m_min.pop();
}

template<typename T> const T& StackWithMin<T>::min() const
{
	assert(m_data.size()>0 && m_min.size()>0);
	return m_min.top();
}
