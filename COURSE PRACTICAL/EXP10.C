#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Structure for message
struct message
{
    long msg_type;
    char msg_text[100];
};

int main()
{
    struct message msg;

    key_t key = ftok("msgqueue", 65);

    // Create message queue
    int msgid = msgget(key, 0666 | IPC_CREAT);

    // Write message
    msg.msg_type = 1;
    printf("Enter message: ");
    fgets(msg.msg_text, sizeof(msg.msg_text), stdin);

    msgsnd(msgid, &msg, sizeof(msg.msg_text), 0);
    printf("Message sent successfully.\n");

    // Read message
    msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0);
    printf("Message received: %s", msg.msg_text);

    // Delete message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
