struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};
void insertFB(struct nodeFB** startFB,int id,int age)
{
	struct nodeFB *node = (struct nodeFB*)malloc(sizeof(struct nodeFB));
	
	node->id = id;
	node->age = age;
	node->next = *startFB;
	*startFB= node;
	
	

}
void insertGS(struct nodeGS** startGS,int id)
{
	struct nodeGS *second_ptr = (struct nodeGS*)malloc(sizeof(struct nodeGS));
	second_ptr->id = id;
	second_ptr ->next = *startGS;
	*startGS = second_ptr;
	
	

	

}
void SortLinkedListFB(struct nodeFB* startFB)
{
    struct nodeFB* node=NULL, *node2= NULL;
    int tempid,tempage;//temp variable to store node data
    node = startFB;

    while(node != NULL)
    { 
		node2 = node;
        while (node2!=NULL)//travel till the second last element 
        {
			if(startFB->id > node2->id)// compare the data of the nodes 
            {
              tempid = startFB->id;
			  tempage = startFB->age;
              startFB->id= node2->id;// swap the data
			  startFB->age = node2->age;
              node2->id= tempid;
			  node2->age = tempage;
            }
           if(node->id > node2->id)// compare the data of the nodes 
            {
              tempid = node->id;
			  tempage = node->age;
              node->id= node2->id;// swap the data
			  node->age = node2->age;
              node2->id= tempid;
			  node2->age = tempage;
            }
			
			
			node2 = node2->next;
			

			
            // move to the next element 
        }
        node = node->next;    // move to the next node
    }
}
void SortLinkedListFB2(struct nodeFB* startFB)
{
    struct nodeFB* node=NULL, *node2= NULL;
    int tempid,tempage;//temp variable to store node data
    node = startFB;
	
    while(node != NULL)
    { 
		node2 = node;
        while (node2!=NULL)//travel till the second last element 
        {
			if(startFB->id < node2->id)// compare the data of the nodes 
            {
              tempid = startFB->id;
			  tempage = startFB->age;
              startFB->id= node2->id;// swap the data
			  startFB->age = node2->age;
              node2->id= tempid;
			  node2->age = tempage;
            }
           if(node->id < node2->id)// compare the data of the nodes 
            {
              tempid = node->id;
			  tempage = node->age;
              node->id= node2->id;// swap the data
			  node->age = node2->age;
              node2->id= tempid;
			  node2->age = tempage;
            }
			
			
			node2 = node2->next;
			

			
            // move to the next element 
        }
        node = node->next;    // move to the next node
    }
}
void SortLinkedListGS(struct nodeGS* startGS)
{
    struct nodeGS* node=NULL, *node2 = NULL;
    int tempid;//temp variable to store node data
    node = startGS;
    while(node != NULL)
    {
        node2=node; 
        while (node2 !=NULL) 
        {
			if(node2->id > startGS->id)
			{
				//printf("\n%s %d","id",startGS->id);
				tempid = startGS->id;
            	startGS->id= node2->id;// swap the data
				node2->id = tempid;
				
			}


           if(node2->id > node->id)
            {
              	
			  tempid = node->id;
              node->id= node2->id;// swap the data
			  node2->id = tempid;
              
			  
            }
			
         node2 = node2->next;     
        }
        node = node->next;    
    }
	
}
void SortLinkedListGS2(struct nodeGS* startGS)
{
    struct nodeGS* node=NULL, *node2 = NULL;
    int tempid;//temp variable to store node data
    node = startGS;
    while(node != NULL)
    {
        node2=node; 
        while (node2 !=NULL) 
        {
			if(node2->id < startGS->id)
			{
				//printf("\n%s %d","id",startGS->id);
				tempid = startGS->id;
            	startGS->id= node2->id;// swap the data
				node2->id = tempid;
				
			}


           if(node2->id < node->id)
            {
              	
			  tempid = node->id;
              node->id= node2->id;// swap the data
			  node2->id = tempid;
              
			  
            }
			
         node2 = node2->next;     
        }
        node = node->next;    
    }
	
}

void printFB(struct nodeFB* startFB)
{
	
	
	struct nodeFB* ptr1 = startFB;
	SortLinkedListFB(startFB);
	while(ptr1 != NULL)
	{
		
		printf("%d %d\n",ptr1->id,ptr1->age);
		ptr1 = ptr1->next;
	}
	SortLinkedListFB2(startFB);
	puts("");
	
}


void printGS(struct nodeGS* startGS)
{
	SortLinkedListGS(startGS);
	struct nodeGS* ptr2 = startGS;
	
	while(ptr2 != NULL)
	{
		printf("%d\n",ptr2->id);
		ptr2 = ptr2->next;
	}
	SortLinkedListGS2(startGS);
	puts("");
	
}



void createFinalList(struct newNodeFB** startNewFB,struct nodeFB* startFB,struct nodeGS* startGS)
{
	struct newNodeFB* ptrFB = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
	struct newNodeGS* ptrGS = (struct newNodeGS*)malloc(sizeof(struct newNodeGS));


	
	while(startFB!= NULL)
	{
		
		
		ptrFB = (struct newNodeFB*)malloc(sizeof(struct newNodeGS)*sizeof(struct newNodeFB));
		ptrGS = (struct newNodeGS*)malloc(sizeof(struct newNodeGS)*sizeof(struct newNodeFB));
		ptrGS->id = startGS->id;
		ptrGS->next = *startNewFB;
		ptrFB->id = startFB->id;
		ptrFB->age =startFB->age;
		ptrFB->next = ptrGS;
		
		
		startFB = startFB->next;
		startGS = startGS->next;
		
		if(ptrFB !=NULL) 
		{
			
			*startNewFB = ptrFB;
			
		}
		
			


		//printf("%d %d\n",ptrFB->id,ptrFB->age);
		//printf("%d\n",ptrFB->next->id);
		//printf("%s","controlled");
	}
	

	
	
	
	
	
}

void printAll(struct newNodeFB *startNewFB)
{
	
	//printf("%s\n","controlledddd");

	struct newNodeFB *ptrFB = startNewFB;
	struct newNodeGS *ptrGS = startNewFB->next;
	
	
	//printf("%d %d\n",startNewFB->id,startNewFB->next->id);
	
	
	while(ptrFB != NULL)
	{
		//printf("%s","not empty");
		printf("%d %d\n",ptrFB->id,ptrFB->age);
		printf("%d\n",ptrFB->next->id);
		ptrFB =ptrFB->next->next;

	}
	
}





// You must write all the function definitions to be used in this lab into this file. 
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.



