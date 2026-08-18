#include <stdio.h>  
#include <stdbool.h> 

#define MAX_EVENTS 200

struct Event{
    int eventID;
    char eventName[100];
    char date[20];
    char time[20];
    int isCancelled;
};

struct Event events[MAX_EVENTS]; 
  
int eventCount = 0;

//function declaration
void addEvent();
void displayUpcomingEvents();
void cancelEvent();
void viewPastEvents();

int main()
{
    FILE *fptr;  	
    fptr = fopen("event_records.txt", "a+"); 
    int option=0;
    do{
    printf("1. Add Event\n");
    printf("2. Display Upcoming Events\n");
    printf("3. Cancel Event\n");
    printf("4. View Past Events\n");
    printf("5. Exit\n");

    printf("Enter an option (1-5): ");
    scanf("%d", &option);

    printf("\n");

    switch (option){
            case 1:
                addEvent();   //function call
                	break;
            case 2:
                displayUpcomingEvents();
                	break;
            case 3:
                cancelEvent();
                	break;
            case 4:
                viewPastEvents();
                	break;
            case 5:
                printf("EXITING!!!\n");
                	break;
            default:
                printf("ERROR: Invalid option, please try again\n\n");
        }
    }
    while(option!=5);
	return 0;
}

void addEvent(){		
    if (eventCount>=MAX_EVENTS){
        printf("ERROR: Cannot add more events! The event list is full\n");
        return;
    }

    printf("Enter event id: ");
    scanf("%d", &events[eventCount].eventID);		
    printf("Enter event name: ");
    scanf("%s", events[eventCount].eventName);
    printf("Enter event date (DD-MM-YYYY): ");
    scanf("%s", events[eventCount].date);
    printf("Enter event time (HH:MM): ");
    scanf("%s", events[eventCount].time);

    events[eventCount].isCancelled = 0; 
	
    FILE *fptr = NULL;
    
    fptr=fopen("event_records.txt","a+");

    if (fptr== NULL){
        printf("ERROR: Could not add event to file\n\n");
        return;
    }
	fprintf(fptr, "%d | %s | %s | %s | %d\n", events[eventCount].eventID, events[eventCount].eventName, events[eventCount].date, events[eventCount].time, events[eventCount].isCancelled);
    fclose(fptr);
    eventCount++; 								//	events[0]=  1 event mera isme hai

    printf("\nEvent added successfully!\n\n");
}

void displayUpcomingEvents(){
    FILE *fptr;
    fptr =fopen("event_records.txt","r");

    if(fptr==NULL){
        printf("ERROR: event_records.txt file does not exist\n\n");
        return;
    }

    struct Event event;
    bool found = false; //0

    printf("\nUpcoming Events:\n\n");
    					
    while (fscanf(fptr, "%d | %99[^|] | %19[^|] | %19[^|] | %d\n", &event.eventID, event.eventName, event.date, event.time, &event.isCancelled) == 5){
        if (event.isCancelled == 0){ 							
            printf("ID: %d, Name: %s, Date: %s, Time: %s\n", event.eventID, event.eventName, event.date, event.time);
            found=true;
        }
    }
	if(!found){
        printf("No upcoming events found.\n");
    }
    
   fclose(fptr);
}

void cancelEvent(){
    int id;
    printf("Enter the event id to cancel: ");
    scanf("%d", &id);
    
    bool eventFound = false;
    for (int i = 0; i < eventCount; i++){
        if(events[i].eventID==id){
            if(events[i].isCancelled==1){
                printf("Event is already cancelled\n");
            }else{
                events[i].isCancelled = 1;
                printf("Event cancelled successfully\n");
            }
            eventFound=true;
            break;
        }
    }

    if(!eventFound)
    {
        printf("EventID not found.\n");
        return;
    }

   
    FILE *file=fopen("event_records.txt", "w");
    if(file==NULL){
        printf("Error: Unable to save events to file.\n");
        return;
    }

    for(int i=0;i<eventCount;i++){
        fprintf(file, "%d | %s | %s | %s | %d\n", events[i].eventID, events[i].eventName, events[i].date, events[i].time, events[i].isCancelled);
    }
    fclose(file);
}

void viewPastEvents()
{
    FILE *fptr;
    fptr=fopen("event_records.txt", "r");

    if (fptr==NULL){
        printf("ERROR: event_records.txt file does not exist\n\n");
        return;
    }
    struct Event event;
    bool found=false;
    printf("Past Events:\n\n");
    while(fscanf(fptr, "%d | %99[^|] | %19[^|] | %19[^|] | %d\n", &event.eventID, event.eventName, event.date, event.time, &event.isCancelled) == 5){
        if(event.isCancelled == 1){
            printf("ID: %d, Name: %s, Date: %s, Time: %s (Cancelled)\n", event.eventID, event.eventName, event.date, event.time);
            found = true;
        }
    }
    if (!found){
        printf("No past events found.\n");
    }
    fclose(fptr);
}
