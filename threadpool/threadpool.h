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
	bool status;//0--δ���䣬1--�ѷ���
	thread::id thread_id;


	bool operator == (const thread::id& thread_id)
	{
		return (this->thread_id == thread_id);
	}
};




class ThreadPool {
private:
	int thread_num;//�̳߳��е��߳�����
	vector<pool> pl[MAX_NUM];
	queue<void* (*)(void*)> task;//�������
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
