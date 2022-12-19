#pragma once
#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <algorithm>

#define MAX_NUM 20
using namespace std;

struct pool
{
	bool status;//0--未分配，1--已分配
	thread::id thread_id;


	bool operator == (const thread::id& thread_id)
	{
		return (this->thread_id == thread_id);
	}
};




class ThreadPool {
private:
	int thread_num;//线程池中的线程数量
	vector<pool> pl[MAX_NUM];
	queue<void* (*)(void*)> task;//任务队列
	mutex mutex_task;
	mutex mutex_pool;
	thread scheduler;

public:
	ThreadPool(int num);
	void receive_task(void* (*p)());
	void task_schedule();
	void task(void* (*p)());
	void fun();

};
