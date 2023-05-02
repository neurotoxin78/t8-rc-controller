#include "main.h"
#include <Arduino.h>
#include <WiFi.h>
#include "tasks.h"

#define MAX_MOTOR_SPEED 255
#define SERVO_MIN 0
#define SERVO_MAX 180

uint8_t current_command;
uint8_t motor_speed = 0;
uint8_t servo_pos = 90;

TaskHandle_t heartbeat_Task_Handler;
TaskHandle_t drive_Task_Handler; 
TaskHandle_t servo_Task_Handler; 

void createTasks(void)
{
    xTaskCreatePinnedToCore(heartbeat_Task, "HEARTBEAT", 2000, NULL, 1, &heartbeat_Task_Handler, 0);
    xTaskCreatePinnedToCore(drive_Task, "MOTOR_CTRL", 2000, NULL, 1, &drive_Task_Handler, 1);

}

void heartbeat_Task(void *parameter)
{
    for (;;)
    {
        digitalWrite(LED, HIGH);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        digitalWrite(LED, LOW);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        digitalWrite(LED, HIGH);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        digitalWrite(LED, LOW);
        vTaskDelay(2900 / portTICK_PERIOD_MS);
    }
}

void drive_Task(void *parameter)
{
    char out_buffer[100];
    for (;;)
    {
        if (new_command == UP_CMD) // UP
        {
            if (motor_speed != MAX_MOTOR_SPEED)
            {
                motor_speed += 1;
            }
        }
        if (new_command == DOWN_CMD) // DOWN
        {
            if (motor_speed != 0)
            {
                motor_speed -= 1;
            }
        }

        if (new_command == LEFT_CMD) // LEFT
        {
            if (servo_pos != SERVO_MAX)
            {
                servo_pos += 1;
            }
        }
        if (new_command == RIGHT_CMD) // RIGHT
        {
            if (servo_pos != SERVO_MIN)
            {
                servo_pos -= 1;
            }
        }

        if (new_command == ENTER_CMD) // ENTER
        {
            if (servo_pos != 90)
            {
                servo_pos = 90;
            }
        }

        if (new_command == L_BTN_CMD) // ENTER
        {
            if (motor_speed != 0)
            {
                motor_speed = 0;
            }
        }

        if (new_command != current_command) // EXEcute There
        {
            snprintf(out_buffer, sizeof(out_buffer), "M%d , S%d", motor_speed, servo_pos);
            Serial.println(out_buffer);
        }
        current_command = new_command; // Reset command vars
        new_command = 0;
        vTaskDelay(1 / portTICK_PERIOD_MS);
    }
}
