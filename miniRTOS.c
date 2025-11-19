#include "miniRTOS.h"

static Task tasks[DEFAULT_TASK_COUNTER];
static unsigned int taskRunning = 0;
static unsigned int currentTask = 0;

void taskYield() {
    currentTask = (currentTask + 1) % 10;
}

int createTask(taskFunction function, void *arg) {
    if (taskRunning >= DEFAULT_TASK_COUNTER) {
        return -1;
    }

    tasks[tasksRunning].function = function;
    tasks[tasksRunning].arg = arg;
    tasks[tasksRunning].ready = 1;

    tasksRunning++;

    return 0;
}

void schedulerLoop() {
    while (1) {
        if (tasks[currentTask].ready) {
            tasks[currentTask].function(
                tasks[currentTask].arg
            );
        }
        taskYield();
    }
}