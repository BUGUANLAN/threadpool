#include "threadpool.h"

ThreadPool::ThreadPool(int num)
{
	thread_num = num;
	scheduler = thread(task_schedule);

}


void ThreadPool::receive_task(void* (*p)())
{
	thread t(task);

}

void fun()
{

}

void ThreadPool::task(void* (*p)())
{
	p();
	thread::id my_id;
	my_id = this_thread::get_id();
	vector<pool>::iterator iter;
	iter = find(pl->begin(), pl->end(), my_id);
	mutex_pool.lock();
	iter->status = 0;
	mutex_pool.unlock();
}