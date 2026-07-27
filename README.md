<img width="2048" height="263" alt="Exam_Registration_Problems_and_Solutions" src="https://github.com/user-attachments/assets/d42c796d-f18c-4d40-abdf-2499469cd89e" />

### Data Structures and Algorithms programs and tasks repository for the EL batch of '29 of CET. 

Upkeeped by fellow contributors

Take care when copying this work. Any plagarism related strikes on your academic materials with copied work from this are not my responsibility.  

This repository has been created with the sole purpose of guidance or a study resourse for fellow classmates B.Tech pursuers and upcoming batches.

### Detailed instructions to document the code and keep it neat and clean. 

Importance must be given to the header documentation where the Aim of the program, date, version number, author should be mandatory. It is reccomended that function prototypes be used so that the main function displays at the top of the program. Make sure the fucntion prototypes are also documented clearly. Also reccomended to split common actions in main function like accpeting elements into an array into seperate external functions to imporve readability. The contents of the fucntions and subsequent blocks of code must be indented properly using spaces or tabspace. An example of a good documented code is given below:
```c
/****************************************************
 * Program to implement circular queue as an array	*
 * version: 1										*
 * Date: 27 - 7 -26									*
 * Author: Sooraj									*
 ****************************************************/

#include <stdio.h>

#define MAX 10
int queue[MAX];
int front=-1, back=-1;

/* function prototypes */
void enqueue(int value);//fucntion that checks for queue full or empty and inserts the element
int dequeue(void); 		//fucntion that checks for queue empty and dequeues the element
int seeFront(void);		//fucntion that checks for queue empty and just returns the element
void print_queue(void);	//fucntion that checks for queue empty and prints the elements
int isEmpty(void);		//fucntion that checks for queue empty - if the initial case is triggered
int isFull(void);		//fucntion that checks for queue full - if back is one more than front, 
						//also checks the wrap around case at the end and beggining of the queue.

int main()
{
	//proper indentation
  if (front == -1 && back == -1)
  		return 1;
  	else
  		return 0;
  	}
}

--- other functions---

```

<img width="2048" height="263" alt="Exam_Registration_Problems_and_Solutions" src="https://github.com/user-attachments/assets/ba9ba489-c70d-4b97-8639-6ffc65e4c99d" />

#### USE THE IN BUILT FILE VIEWWER ADJUSTED TO VIEW, COPY OR DOWNLOAD THE PROGRAM FILES WITHIN YOUR BROWSER IN AN INTERACTIVE WAY:



<p align="center">
<a href="https://soorzj.github.io/EEYEL-DSA/">
  <img
    src="https://img.shields.io/badge/soorzj.github.io-EEYEL--DSA-green"
    alt="Website"
    width="70%"
  />
</a>
