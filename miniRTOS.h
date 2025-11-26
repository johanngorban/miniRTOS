#pragma once

#define DEFAULT_TASK_COUNTER 16

typedef enum {
    TASK_NEW,
    TASK_AWAITING,
    TASK_RUNNING
    TASK_TERMINATED,
} TaskStatus;

typedef TaskStatus (*taskFunction)(void *);

typedef struct {
    taskFunction function;
    void *arg;
    char ready;
} Task;

void taskYield();

int createTask(taskFunction function, void *arg);

void schedulerLoop();