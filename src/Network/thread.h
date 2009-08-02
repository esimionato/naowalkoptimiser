#ifndef THREAD_H_DEFINED
#define THREAD_H_DEFINED

// Wrapper class for threading.

#include <pthread.h>
#include <string>

class Thread
{
	public:
		Thread(std::string _name);
		virtual int start();
		virtual void stop();
		virtual void run() = 0; // To be overridden by code to run.

	private:
		static void* runThread(void* _thread);

	public:
		const std::string name;

	private:
		pthread_t thread;

	protected:
		bool running;
		
};
#endif
