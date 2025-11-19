#pragma once

#define DEFAULT_TASK_COUNTER 16

typedef void (*taskFunction)(void *);

typedef struct {
    taskFunction function;
    void *arg;
    char ready;
} Task;

void taskYield();

int createTask(taskFunction function, void *arg);

void schedulerLoop();