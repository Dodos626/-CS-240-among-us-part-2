/***************************************************************
 *                                                             *
 * file: main.cpp                                              *
 *                                                             *
 * @Author  Skerdi Basha                         		   	   *
 * @Version 1-12-2020                             			   *
 * @email   sbash@csd.uoc.gr                                   *
 *                                                             *
 * @brief   Main function and implemetantion of among_us.h     *
 *          for the needs of CS-240 project 2020               *
 *                                                             *
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <iostream>
#include <vector>
#include <time.h>
#include "among_us.h"

using namespace std;
//hash function and whatever it needs ---------------------

int hash_function(int x);
int p, a, b;



//CUSTOM ---------------------------------------------------
Player * delete_player(Player *tmp , int pid);
Player * Findthesmallestplayer(Player *tmp);
Task * delete_task(Task *tmp , int tid);
Task * Findthesmallest(Task *tmp);
void InOrder_players(Player *tmp);
void InOrder_players_tasks(Task *tmp);
Task *to_distribute();
int In_order_distribution(Player *current_player , int x);
void InOrder(Player *tmp);
Player *globalsentinel;
void task_to_pq(Task *to_put);
Task *sixwneusi(Task* p , Task* p2);
void task_tree_to_array(Task **array,int &current,Task *p);
Task * array_to_tree(Task **array,int start,int end);
void print_in_order_suspect(Player *tmp);
Player * FindInorderSuccessor(Player *root);
Player * FindInorderPredecessor(Player *root);
Player * most_evidence();
void from_pq_to_player(Player *root);
//----------------------------------------------------------
unsigned int primes_g[650] = {
	179,
	181,
	191,
	193,
	197,
	199,
	211,
	223,
	227,
	229,
	233,
	239,
	241,
	251,
	257,
	263,
	269,
	271,
	277,
	281,
	283,
	293,
	307,
	311,
	313,
	317,
	331,
	337,
	347,
	349,
	353,
	359,
	367,
	373,
	379,
	383,
	389,
	397,
	401,
	409,
	419,
	421,
	431,
	433,
	439,
	443,
	449,
	457,
	461,
	463,
	467,
	479,
	487,
	491,
	499,
	503,
	509,
	521,
	523,
	541,
	547,
	557,
	563,
	569,
	571,
	577,
	587,
	593,
	599,
	601,
	607,
	613,
	617,
	619,
	631,
	641,
	643,
	647,
	653,
	659,
	661,
	673,
	677,
	683,
	691,
	701,
	709,
	719,
	727,
	733,
	739,
	743,
	751,
	757,
	761,
	769,
	773,
	787,
	797,
	809,
	811,
	821,
	823,
	827,
	829,
	839,
	853,
	857,
	859,
	863,
	877,
	881,
	883,
	887,
	907,
	911,
	919,
	929,
	937,
	941,
	947,
	953,
	967,
	971,
	977,
	983,
	991,
	997,
	1009,
	1013,
	1019,
	1021,
	1031,
	1033,
	1039,
	1049,
	1051,
	1061,
	1063,
	1069,
	1087,
	1091,
	1093,
	1097,
	1103,
	1109,
	1117,
	1123,
	1129,
	1151,
	1153,
	1163,
	1171,
	1181,
	1187,
	1193,
	1201,
	1213,
	1217,
	1223,
	1229,
	1231,
	1237,
	1249,
	1259,
	1277,
	1279,
	1283,
	1289,
	1291,
	1297,
	1301,
	1303,
	1307,
	1319,
	1321,
	1327,
	1361,
	1367,
	1373,
	1381,
	1399,
	1409,
	1423,
	1427,
	1429,
	1433,
	1439,
	1447,
	1451,
	1453,
	1459,
	1471,
	1481,
	1483,
	1487,
	1489,
	1493,
	1499,
	1511,
	1523,
	1531,
	1543,
	1549,
	1553,
	1559,
	1567,
	1571,
	1579,
	1583,
	1597,
	1601,
	1607,
	1609,
	1613,
	1619,
	1621,
	1627,
	1637,
	1657,
	1663,
	1667,
	1669,
	1693,
	1697,
	1699,
	1709,
	1721,
	1723,
	1733,
	1741,
	1747,
	1753,
	1759,
	1777,
	1783,
	1787,
	1789,
	1801,
	1811,
	1823,
	1831,
	1847,
	1861,
	1867,
	1871,
	1873,
	1877,
	1879,
	1889,
	1901,
	1907,
	1913,
	1931,
	1933,
	1949,
	1951,
	1973,
	1979,
	1987,
	1993,
	1997,
	1999,
	2003,
	2011,
	2017,
	2027,
	2029,
	2039,
	2053,
	2063,
	2069,
	2081,
	2083,
	2087,
	2089,
	2099,
	2111,
	2113,
	2129,
	2131,
	2137,
	2141,
	2143,
	2153,
	2161,
	2179,
	2203,
	2207,
	2213,
	2221,
	2237,
	2239,
	2243,
	2251,
	2267,
	2269,
	2273,
	2281,
	2287,
	2293,
	2297,
	2309,
	2311,
	2333,
	2339,
	2341,
	2347,
	2351,
	2357,
	2371,
	2377,
	2381,
	2383,
	2389,
	2393,
	2399,
	2411,
	2417,
	2423,
	2437,
	2441,
	2447,
	2459,
	2467,
	2473,
	2477,
	2503,
	2521,
	2531,
	2539,
	2543,
	2549,
	2551,
	2557,
	2579,
	2591,
	2593,
	2609,
	2617,
	2621,
	2633,
	2647,
	2657,
	2659,
	2663,
	2671,
	2677,
	2683,
	2687,
	2689,
	2693,
	2699,
	2707,
	2711,
	2713,
	2719,
	2729,
	2731,
	2741,
	2749,
	2753,
	2767,
	2777,
	2789,
	2791,
	2797,
	2801,
	2803,
	2819,
	2833,
	2837,
	2843,
	2851,
	2857,
	2861,
	2879,
	2887,
	2897,
	2903,
	2909,
	2917,
	2927,
	2939,
	2953,
	2957,
	2963,
	2969,
	2971,
	2999,
	3001,
	3011,
	3019,
	3023,
	3037,
	3041,
	3049,
	3061,
	3067,
	3079,
	3083,
	3089,
	3109,
	3119,
	3121,
	3137,
	3163,
	3167,
	3169,
	3181,
	3187,
	3191,
	3203,
	3209,
	3217,
	3221,
	3229,
	3251,
	3253,
	3257,
	3259,
	3271,
	3299,
	3301,
	3307,
	3313,
	3319,
	3323,
	3329,
	3331,
	3343,
	3347,
	3359,
	3361,
	3371,
	3373,
	3389,
	3391,
	3407,
	3413,
	3433,
	3449,
	3457,
	3461,
	3463,
	3467,
	3469,
	3491,
	3499,
	3511,
	3517,
	3527,
	3529,
	3533,
	3539,
	3541,
	3547,
	3557,
	3559,
	3571,
	3581,
	3583,
	3593,
	3607,
	3613,
	3617,
	3623,
	3631,
	3637,
	3643,
	3659,
	3671,
	3673,
	3677,
	3691,
	3697,
	3701,
	3709,
	3719,
	3727,
	3733,
	3739,
	3761,
	3767,
	3769,
	3779,
	3793,
	3797,
	3803,
	3821,
	3823,
	3833,
	3847,
	3851,
	3853,
	3863,
	3877,
	3881,
	3889,
	3907,
	3911,
	3917,
	3919,
	3923,
	3929,
	3931,
	3943,
	3947,
	3967,
	3989,
	4001,
	4003,
	4007,
	4013,
	4019,
	4021,
	4027,
	4049,
	4051,
	4057,
	4073,
	4079,
	4091,
	4093,
	4099,
	4111,
	4127,
	4129,
	4133,
	4139,
	4153,
	4157,
	4159,
	4177,
	4201,
	4211,
	4217,
	4219,
	4229,
	4231,
	4241,
	4243,
	4253,
	4259,
	4261,
	4271,
	4273,
	4283,
	4289,
	4297,
	4327,
	4337,
	4339,
	4349,
	4357,
	4363,
	4373,
	4391,
	4397,
	4409,
	4421,
	4423,
	4441,
	4447,
	4451,
	4457,
	4463,
	4481,
	4483,
	4493,
	4507,
	4513,
	4517,
	4519,
	4523,
	4547,
	4549,
	4561,
	4567,
	4583,
	4591,
	4597,
	4603,
	4621,
	4637,
	4639,
	4643,
	4649,
	4651,
	4657,
	4663,
	4673,
	4679,
	4691,
	4703,
	4721,
	4723,
	4729,
	4733,
	4751,
	4759,
	4783,
	4787,
	4789,
	4793,
	4799,
	4801,
	4813,
	4817,
	4831,
	4861,
	4871,
	4877,
	4889,
	4903,
	4909,
	4919,
	4931,
	4933,
	4937,
	4943,
	4951,
	4957,
	4967,
	4969,
	4973,
	4987,
	4993,
	4999,
	5003,
	5009,
	5011,
	5021,
	5023,
	5039,
	5051,
	5059,
	5077,
	5081,
	5087,
	5099,
	5101,
	5107,
	5113,
	5119,
	5147,
	5153,
	5167,
	5171,
	5179,
};

/**
 * @brief Optional function to initialize data structures that 
 *        need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
int initialize()
{

	//initialize the player by making the pointer point at the sentinel
	players_tree = new Player;
	players_tree->evidence = -1;
	players_tree->is_alien = -1;
	players_tree->pid = -1;
	players_tree->parrent = NULL;
	players_tree->tasks = NULL;
	players_tree->rc = NULL;
	players_tree->lc = NULL;
	globalsentinel=players_tree;
	//initialize the hash function
	srand(time(NULL));
	//in case of failing to find a prime big enough it will be set as the max_tid_g
	p = max_tid_g;
	for (size_t i = 0; i < 650; i++)
	{
		if (primes_g[i] > max_tid_g)
		{
			p = primes_g[i];
			break;
		}
	}
	// 1 <= a <= p-1
	a = (rand() % (p - 1) + 1);
	// 0 <= b <= p-1
	b = (rand() % p);
	
	//initialize general task hash table size of max_tasks_g
	general_tasks_ht.count = 0;
	general_tasks_ht.tasks = new HT_Task *[max_tasks_g](); //every pointer is initialized null


	//initialize the completed tasks pq
	completed_tasks_pq.size=0;
	completed_tasks_pq.tasks=new HT_Task[max_tasks_g]();

	
	
	
	return 1;
}

int hash_function(int x)
{
	return ((a * x + b) % p) % max_tasks_g;
}

/**
 * @brief Register Player
 *
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid, int is_alien)
{

	//in case there is only the sentinel
	if (players_tree->pid == -1)
	{
		//initializes the new tree node that will become first
		Player *to_put = new Player;
		to_put->evidence = 0;
		to_put->is_alien = is_alien;
		to_put->pid = pid;
		to_put->parrent = NULL;
		to_put->tasks = NULL; //tasks will initialize by giving the first one
		to_put->lc = players_tree;
		to_put->rc = players_tree;
		players_tree = to_put;
		return 1;
	}

	//searches for the last player before the sentinel
	//suitable to enter the new one
	Player *p = players_tree;
	while (1)
	{
		//if it wants to go right
		if (p->pid < pid)
		{
			//it checks if right is the last node
			//if it is it breaks the loop and continues
			if (p->rc->pid == -1)
			{
				break;
			}
			p = p->rc;
		}
		else
		{
			//exactly same concept for going left
			if (p->lc->pid == -1)
			{
				break;
			}
			p = p->lc;
		}
	}

	Player *to_put = new Player;
	to_put->evidence = 0;
	to_put->is_alien = is_alien;
	to_put->pid = pid;
	to_put->parrent = p;
	to_put->tasks = NULL;

	//searches wich pointer points at the sentinel and
	//makes the two new pointers of the new player point there
	if (p->lc->pid == -1)
	{
		to_put->lc = p->lc;
		to_put->rc = p->lc;
	}
	else
	{
		to_put->lc = p->rc;
		to_put->rc = p->rc;
	}
	//looks if the new tree node must enter at the right or the left of the last node
	if (p->pid < pid)
	{
		p->rc = to_put;
	}
	else
	{
		p->lc = to_put;
	}

	print_players();

	return 1;
}

/**
 * @brief Insert Task in the general task hash table
 *
 * @param tid The task id
 * 
 * @param difficulty The difficulty of the task
 *
 * @return 1 on success
 *         0 on failure
 */
int insert_task(int tid, int difficulty)
{
	general_tasks_ht.count++;
	int hash_num = hash_function(tid);

	//initializes the new task to be put
	HT_Task *to_put = new HT_Task;
	to_put->difficulty = difficulty;
	to_put->next = NULL;
	to_put->tid = tid;

	//if hash table at that cell doesnt have a task
	if (general_tasks_ht.tasks[hash_num] == NULL)
	{
		general_tasks_ht.tasks[hash_num] = to_put;

		print_tasks();

		return 1;
	}
	//the new cell is put in the beggining
	to_put->next = general_tasks_ht.tasks[hash_num];
	general_tasks_ht.tasks[hash_num] = to_put;

	print_tasks();

	return 1;
}

/**
 * @brief Distribute Tasks to the players
 * @return 1 on success
 *         0 on failure
 */
int current_hash_num;
HT_Task *current_hash_task;

int distribute_tasks()
{
	//will initialise the global variables that will help to distribute
	current_hash_num=0;
	while (general_tasks_ht.tasks[current_hash_num]==NULL)
	{
		current_hash_num++;
	}
	current_hash_task=general_tasks_ht.tasks[current_hash_num];
	//x holds the tasks count
	int x = general_tasks_ht.count ;
	//while x isnt 0
	while (x!=0)
	{
		//inorder fashion distribute the tasks to players
		x = In_order_distribution(players_tree,x);	
	}
	print_double_tree();
	return 1;
}

//it will traverse the tree inorder and call the *to_distribute every time it finds a non alien player
int In_order_distribution(Player *current_player , int x){

	//if we hit a bottom or x ended
	if ((x==0)||(current_player->pid==-1))
	{
		return x ;
	}
	
	x=In_order_distribution(current_player->lc,x);
	if (x==0){return x;}
	
	//here i need to find the suitable place for the task in the task bts of the player
	if (current_player->is_alien==0)
	{
		//to distribute returns the next in line in the hash table 
		Task *to_put = to_distribute();
		
		Task *tmp = current_player->tasks;
		
		//traverses the players tasks tree to find the spot
		//in case there is no other task
		if (tmp==NULL)
		{
			current_player->tasks = to_put;
			
		}else
		{
			while (1)
			{
				//if new tid is smaller than current it goes at left
				if (tmp->tid>to_put->tid)
				{
					tmp->lcnt++;
					//if there isnt anything at left it goes there and breaks the while
					if (tmp->lc==NULL)
					{
						tmp->lc=to_put;
						break;
					}else  //otherwise its continues at the left to search
					{
						tmp=tmp->lc;
					}
				}else //exactly the same thing with the right side if the new tid is bigger than the current
				{
					if (tmp->rc==NULL)
					{
						tmp->rc=to_put;
						break;
					}else
					{
						tmp=tmp->rc;
					}
				}
			}
		}
		//x gets smaller as we successfuly distributed 1 task
		x=x-1;
		
	}
	
	x=In_order_distribution(current_player->rc,x);
	
	return x;
}

Task *to_distribute(){
	//initializes the new task to give to player
	Task *new_task = new Task;
	new_task->difficulty=current_hash_task->difficulty;
	new_task->lc=NULL;
	new_task->rc=NULL;
	new_task->lcnt=0;
	new_task->tid=current_hash_task->tid;

	//searches the hash table for the next eligible task
	if (current_hash_task->next==NULL)
	{
		current_hash_num++;
		while (general_tasks_ht.tasks[current_hash_num]==NULL)
		{
			current_hash_num++;
		}
		current_hash_task=general_tasks_ht.tasks[current_hash_num];
	}else
	{
		current_hash_task=current_hash_task->next;
	}
	
	
	return new_task;
}

/**
 * @brief Implement Task
 *
 * @param pid The player's id
 *
 * @param tid The task's tid
 *
 * @return 1 on success
 *         0 on failure
 */
int implement_task(int pid, int tid)
{
	Player *tmp_player=players_tree;
	while (tmp_player->pid!=-1)
	{
		//if found
		if (tmp_player->pid==pid)
		{
			break;
		}
		
		if(tmp_player->pid>pid){
			tmp_player=tmp_player->lc;
		}else
		{
			tmp_player=tmp_player->rc;
		}
	}
	//in case there is no such player
	if (tmp_player->pid==-1)
	{
		
		return 0;
	}
	//if given player has 0 tasks
	if (tmp_player->tasks==NULL)
	{
		
		return 0;
	}
	Task *tmp_task=tmp_player->tasks;
	while (tmp_task!=NULL)
	{
		if (tmp_task->tid==tid)
		{
			break ;
		}
		
		if (tmp_task->tid>tid)
		{
			tmp_task=tmp_task->lc;
		}else
		{
			tmp_task=tmp_task->rc;
		}
		
		
	}
	if (tmp_task==NULL)
	{
		
		return 0;
	}
	tmp_player->tasks=delete_task(tmp_player->tasks,tid);
	print_double_tree();
	print_pq();
	return 1;
}

/**it finds the task with the given tmp and deletes it 
and fixes the tree by taking the leftmost of the right side and putting it 
as root, it returns the root*/
Task * delete_task(Task *tmp , int tid){
	if(tmp==NULL){return tmp;}

	//for going into the right side
	if (tid > tmp->tid)
	{
		tmp->rc=delete_task(tmp->rc,tid);
	}else if (tid < tmp->tid) //for going into the left side
	{
		//whenever going left lcnt goes down by one
		tmp->lcnt--;
		tmp->lc=delete_task(tmp->lc,tid);
	}else //if key is found
	{
		if (tmp->lc == NULL) {
            Task * temp = tmp->rc;
			
			task_to_pq(tmp);
            free(tmp);
            return temp;
        }
        else if (tmp->rc == NULL) {
            Task * temp = tmp->lc;
			
			task_to_pq(tmp);
            free(tmp);
            return temp;
        }
		//Finds the smallest key and puts it into the deleted place
		Task * temp = Findthesmallest(tmp->rc);
		task_to_pq(tmp);
		tmp->tid=temp->tid;
		tmp->difficulty=temp->difficulty;
		tmp->rc=delete_task(tmp->rc,tmp->tid);
	}
	return tmp;
	
	
}
Task * Findthesmallest(Task *tmp){
	Task * to_search = tmp;
 
    /* loop down to find the leftmost leaf */
    while (to_search && to_search->lc != NULL)
        to_search = to_search->lc;
 
    return to_search;
}
void task_to_pq(Task *to_put){
	

	if (completed_tasks_pq.size==max_tasks_g)
	{
		return ;
	}
	completed_tasks_pq.tasks[completed_tasks_pq.size].difficulty=to_put->difficulty;
	completed_tasks_pq.tasks[completed_tasks_pq.size].next=NULL;
	completed_tasks_pq.tasks[completed_tasks_pq.size].tid=to_put->tid;
	completed_tasks_pq.size++;

	HT_Task temp;
	int i,j;
	for(i=0;i<completed_tasks_pq.size-1;i++){
		
		for (j = i+1; j < completed_tasks_pq.size; j++)
		{
			if (completed_tasks_pq.tasks[j].difficulty>completed_tasks_pq.tasks[i].difficulty)
			{
				
				temp = completed_tasks_pq.tasks[i];
				completed_tasks_pq.tasks[i] = completed_tasks_pq.tasks[j];
				completed_tasks_pq.tasks[j]=temp;
			}
			
		}
		
	}

	return;
	
}


/**
 * @brief Eject Player
 * 
 * @param pid_1 The ejected player's id
 *
 * @param pid_2 The crewmates id
 *
 * @return 1 on success
 *         0 on failure
 */
int eject_player(int pid_1, int pid_2)
{
	if (pid_1==pid_2)
	{
		
		return 0;
	}
	

	//Looks for the pid_1 player
	Player *tmp_player= players_tree;
	while (tmp_player->pid!=-1)
	{
		//if found
		if (tmp_player->pid==pid_1)
		{
			break;
		}
		
		if(tmp_player->pid>pid_1){
			tmp_player=tmp_player->lc;
		}else
		{
			tmp_player=tmp_player->rc;
		}
	}
	//in case there is no such player
	if (tmp_player->pid==-1)
	{
	
		return 0;
	}
	
	//looks for the pid_2 player
	Player *tmp_player2= players_tree;
	while (tmp_player2->pid!=-1)
	{
		//if found
		if (tmp_player2->pid==pid_2)
		{
			break;
		}
		
		if(tmp_player2->pid>pid_2){
			tmp_player2=tmp_player2->lc;
		}else
		{
			tmp_player2=tmp_player2->rc;
		}
	}
	//if players is alien
	if (tmp_player->is_alien==1)
	{
		return 0;
	}
	
	//in case there is no such player
	if (tmp_player2->pid==-1)
	{
		return 0;
	}

	if (tmp_player2->tasks==NULL)
	{
		tmp_player2->tasks=tmp_player->tasks;
	}else if (tmp_player->tasks!=NULL){
		tmp_player2->tasks=sixwneusi(tmp_player->tasks,tmp_player2->tasks);
		
	}
	
	

	players_tree=delete_player(players_tree,pid_1);
	
	
	print_double_tree();
	

	return 1;
}
Player * delete_player(Player *tmp , int pid){
	if(tmp->pid==-1){return tmp;}
	
	//for going into the right side
	if (pid > tmp->pid)
	{
		tmp->rc=delete_player(tmp->rc,pid);
	}else if (pid < tmp->pid) 
	//for going into the left side
	{
		
		tmp->lc=delete_player(tmp->lc,pid);
	}else //if key is found
	{
		if (tmp->lc->pid==-1 && tmp->rc->pid==-1)
		{
			return tmp->lc;
		}
		
		if (tmp->lc->pid == -1) {
            Player * temp = tmp->rc;
			temp->parrent = tmp->parrent;
            free(tmp);
            return temp;
        }
        else if (tmp->rc->pid == -1) {
            Player * temp = tmp->lc;
			temp->parrent = tmp->parrent;
            free(tmp);
			
            return temp;
        }

		//Finds the smallest key and puts it into the deleted place
		Player * temp = Findthesmallestplayer(tmp->rc);

		
		tmp->pid=temp->pid;
		tmp->tasks=temp->tasks;
		tmp->is_alien=temp->is_alien;
		tmp->evidence=temp->evidence;
		
		if (tmp->rc->pid!=-1)
		{
			tmp->rc=delete_player(tmp->rc,tmp->pid);
		}
	}
	return tmp;
}
Player * Findthesmallestplayer(Player *tmp){
	Player * to_search = tmp;
	
    /* loop down to find the leftmost leaf */
    while (to_search->lc->pid!=-1)
        to_search = to_search->lc;
 
    return to_search;
}


Task *sixwneusi(Task* p , Task* p2){
	
	int p_size = 0 , p2_size = 0;
	//FOR THE FIRST TASK TREE ===================================================================
	// finds the size of the tree P 
	Task *tmp =p;
	while (tmp!=NULL)
	{
		p_size=p_size + tmp->lcnt + 1;
		tmp=tmp->rc;
	}
	
	//initializes the arrayA to be p_size
	Task **arrayA=new Task*[p_size];



	Task *temp=p;
	int current=0;
	task_tree_to_array(arrayA,current,temp);

	//FOR THE SECOND TASK TREE ======================================================================
	tmp =p2;
	while (tmp!=NULL)
	{
		p2_size=p2_size + tmp->lcnt + 1;
		tmp=tmp->rc;
	}
	
	//initializes the arrayB to be p2_size
	Task **arrayB=new Task*[p2_size];

	temp=p2;
	current=0;
	task_tree_to_array(arrayB,current,temp);




	Task **final_array=new Task*[p_size+p2_size];
	
	int i=0,j=0,k=0;
	while (i<p_size && j <p2_size)
	{
		if (arrayA[i]->tid<arrayB[j]->tid)
		{
			final_array[k++]=arrayA[i++];
		
		}else
		{
			final_array[k++]=arrayB[j++];
		
		}
	}
	while (i<p_size)
	{
		final_array[k++]=arrayA[i++];
	}
	while (j<p2_size)
	{
		final_array[k++]=arrayB[j++];
	}

	


	return array_to_tree(final_array,0,p_size+p2_size-1);
	
	
    
}

void task_tree_to_array(Task **array,int &current,Task *p){
	if(p==NULL){return ;}
	task_tree_to_array(array,current,p->lc);
	p->lcnt=0;
	array[current++]=p;
	task_tree_to_array(array,current,p->rc);
}

Task * array_to_tree(Task **array,int start,int end){
	if(start>end){return NULL;}

	int mid = (start+end)/2;
	Task * root=new Task;
	root->tid=array[mid]->tid;
	root->difficulty=array[mid]->difficulty;

	root->lc=array_to_tree(array,start,mid-1);

	root->lcnt=0;
	Task * test_barethika = root->lc;
	
	while (test_barethika!=NULL)
	{
		root->lcnt+= test_barethika->lcnt+1;
		test_barethika=test_barethika->rc;
	}
	
	
	root->rc=array_to_tree(array,mid+1,end);
	return root;

}


/**
 * @brief Witness Eject Player
 *
 * @param pid_1 The ejected player's id
 * 
 * @param pid_2 The crewmate's pid
 *
 * @param pid_a The alien's pid
 * 
 * @param number_of_witnesses The number of witnesses
 *
 * @return 1 on success
 *         0 on failure
 */
int witness_eject(int pid_1, int pid_2, int pid_a, int number_of_witnesses)
{
	
	Player *tmp_player= players_tree;
	while (tmp_player->pid!=-1)
	{
		//if found
		if (tmp_player->pid==pid_a)
		{
			break;
		}
		
		if(tmp_player->pid>pid_a){
			tmp_player=tmp_player->lc;
		}else
		{
			tmp_player=tmp_player->rc;
		}
	}
	if (tmp_player->pid==-1)
	{
		return 0;
	}

	tmp_player->evidence=tmp_player->evidence+number_of_witnesses;
	if (pid_1==pid_2)
	{
		
		return 0;
	}
	

	//Looks for the pid_1 player
	tmp_player= players_tree;
	while (tmp_player->pid!=-1)
	{
		//if found
		if (tmp_player->pid==pid_1)
		{
			break;
		}
		
		if(tmp_player->pid>pid_1){
			tmp_player=tmp_player->lc;
		}else
		{
			tmp_player=tmp_player->rc;
		}
	}
	//in case there is no such player
	if (tmp_player->pid==-1)
	{
	
		return 0;
	}
	
	//looks for the pid_2 player
	Player *tmp_player2= players_tree;
	while (tmp_player2->pid!=-1)
	{
		//if found
		if (tmp_player2->pid==pid_2)
		{
			break;
		}
		
		if(tmp_player2->pid>pid_2){
			tmp_player2=tmp_player2->lc;
		}else
		{
			tmp_player2=tmp_player2->rc;
		}
	}
	//if players is alien
	if (tmp_player->is_alien==1)
	{
		return 0;
	}
	
	//in case there is no such player
	if (tmp_player2->pid==-1)
	{
		return 0;
	}

	if (tmp_player2->tasks==NULL)
	{
		tmp_player2->tasks=tmp_player->tasks;
	}else if (tmp_player->tasks!=NULL){
		tmp_player2->tasks=sixwneusi(tmp_player->tasks,tmp_player2->tasks);
	}
	
	

	players_tree=delete_player(players_tree,pid_1);
	
	print_in_order_suspect(players_tree);
	return 1;
}

void print_in_order_suspect(Player *tmp){
	if (tmp->pid == -1)return;
	InOrder_players(tmp->lc);
	
	cout << "<" << tmp->pid << " , " << tmp->evidence << ">= ";
	if (tmp->tasks==NULL)
	{
		cout << "<Empty task>" <<endl;
	}else
	{
		InOrder_players_tasks(tmp->tasks);	
		cout << endl;
	}
	InOrder_players(tmp->rc);
}



/**
 * @brief Sabotage
 *
 * @param number_of_tasks The number of tasks to be sabotaged
 *
 * @param pid The player's id
 * 
 * @return 1 on success
 *         0 on failure
 */

int sabotage(int number_of_tasks, int pid)
{
	if (completed_tasks_pq.size==0 || completed_tasks_pq.size < number_of_tasks)
	{
		return 0;
	}
	
	Player *tmp = players_tree;
	//search for the player with given pid
	while (tmp->pid!=-1)
	{
		if (tmp->pid==pid)
		{
			break ;
		}
		
		if (tmp->pid>pid)
		{
			tmp=tmp->lc;
		}else
		{
			tmp=tmp->rc;
		}
	}
	//if not found return 0
	if (tmp->pid==-1)
	{
		return 0;
	}

	Player * temp =FindInorderPredecessor(tmp);
	for (int i = 1; i < number_of_tasks/2; i++)
	{
		temp =FindInorderPredecessor(temp);
	}
	//in case we landed on alien
	if (temp->is_alien==1)
	{
		while (temp->is_alien==1)
		{
			temp = FindInorderPredecessor(temp);
		}
		
	}
	
	for (int i = 0; i < number_of_tasks; i++)
	{
		from_pq_to_player(temp);
		temp = FindInorderSuccessor(temp);
		if (temp->is_alien==1)
		{
			while (temp->is_alien==1)
			{
				temp = FindInorderSuccessor(temp);
			}
			
		}
		
	}
	
	print_double_tree();
	
	return 1;
}
Player * FindInorderPredecessor(Player *root){
	Player *tmp = root ;
	if (tmp->lc->pid!=-1)
	{
		tmp = tmp->lc;
		while (tmp->rc->pid!=-1)
		{
			tmp=tmp->rc;
		}
		return tmp;
	}
	
	//in case the prev inorder is the parrent
	while (tmp->parrent->lc==tmp)
	{
		tmp = tmp->parrent;

		//in case we are at root the next will be the rightmost
		if (tmp->parrent==NULL)
		{
			tmp = players_tree;
			while (tmp->rc->pid!=-1)
			{
				tmp=tmp->rc;
			}
			return tmp;
		}
	}
	tmp=tmp->parrent;
	return tmp;
}
Player * FindInorderSuccessor(Player *root){
	Player *tmp = root ;
	
	if (tmp->rc->pid!=-1)
	{
		tmp = tmp->rc;
		while (tmp->lc->pid!=-1)
		{
			tmp=tmp->lc;
		}
		return tmp;
	}
	if (tmp->parrent==NULL)
		{
			tmp = players_tree;
			while (tmp->lc->pid!=-1)
			{
				tmp=tmp->lc;
			}
			return tmp;
		}
	//in case the prev inorder is the parrent
	while (tmp->parrent->rc==tmp)
	{
		tmp = tmp->parrent;

		//in case we are at root the next will be the rightmost
		if (tmp->parrent==NULL)
		{
			tmp = players_tree;
			while (tmp->lc->pid!=-1)
			{
				tmp=tmp->lc;
			}
			return tmp;
		}
	}
	tmp=tmp->parrent;
	return tmp;
}
void from_pq_to_player(Player *root){
	Task * to_ret= new Task;
	to_ret->difficulty=completed_tasks_pq.tasks[0].difficulty;
	to_ret->tid=completed_tasks_pq.tasks[0].tid;
	to_ret->lcnt=0;
	to_ret->lc=NULL;
	to_ret->rc=NULL;


	completed_tasks_pq.tasks[0].difficulty = 0;
	completed_tasks_pq.tasks[0].tid=0;

	HT_Task temp;
	int i,j,min;
	for(i=0;i<completed_tasks_pq.size-1;i++){
		
		for (j = i+1; j < completed_tasks_pq.size; j++)
		{
			if (completed_tasks_pq.tasks[j].difficulty>completed_tasks_pq.tasks[i].difficulty)
			{
				
				temp = completed_tasks_pq.tasks[i];
				completed_tasks_pq.tasks[i] = completed_tasks_pq.tasks[j];
				completed_tasks_pq.tasks[j]=temp;
			}
			
		}
		
	}
	completed_tasks_pq.size--;

	Task *curr = root->tasks;

	if (curr==NULL)
	{
		root->tasks = to_ret;
		return;
	}
	while (curr!=NULL)
	{
		if (curr->tid>to_ret->tid)
		{
			curr->lcnt++;
			if (curr->lc==NULL)
			{
				curr->lc=to_ret;
				return;
			}
			curr=curr->lc;
		}else
		{
			if (curr->rc==NULL)
			{
				curr->rc=to_ret;
				return;
			}
			curr=curr->rc;
		}
		
	}
	
}



/**
 * @brief Vote
 *
 * @param pid_1 The suspicious player's id
 *
 * @param pid_2 The crewmate's pid
 * 
 * @param vote_evidence The vote's evidence
 *
 * @return 1 on success
 *         0 on failure
 */
int vote(int pid_1, int pid_2, int vote_evidence)
{
	
	
	//check for the first player
	Player *tmp_player= players_tree;
	while (tmp_player->pid!=-1)
	{
		//if found
		if (tmp_player->pid==pid_1)
		{
			break;
		}
		
		if(tmp_player->pid>pid_1){
			tmp_player=tmp_player->lc;
		}else
		{
			tmp_player=tmp_player->rc;
		}
	}
	if (tmp_player->pid==-1)
	{
		return 0;
	}
	tmp_player->evidence=tmp_player->evidence+vote_evidence;

	//looks for the pid_2 player
	Player *tmp_player2= players_tree;
	while (tmp_player2->pid!=-1)
	{
		//if found
		if (tmp_player2->pid==pid_2)
		{
			break;
		}
		
		if(tmp_player2->pid>pid_2){
			tmp_player2=tmp_player2->lc;
		}else
		{
			tmp_player2=tmp_player2->rc;
		}
	}
	
	//in case there is no such player
	if (tmp_player2->pid==-1)
	{
		return 0;
	}
	
	Player * to_del=most_evidence();

	//if player to take tasks is the same as the one deleted
	if (to_del->pid==tmp_player2->pid)
	{
		return 0;
	}
	

	if (tmp_player2->tasks==NULL)
	{
		tmp_player2->tasks=to_del->tasks;
	}else if (to_del->tasks!=NULL){
		tmp_player2->tasks=sixwneusi(to_del->tasks,tmp_player2->tasks);
	}
	
	

	players_tree=delete_player(players_tree,to_del->pid);
	
	print_in_order_suspect(players_tree);

	return 1;
}
Player * most_evidence(){
	
	Player *tmp = players_tree;
	Player *to_ret = players_tree;
	tmp=FindInorderSuccessor(tmp);
	if (tmp->evidence>to_ret->evidence)
	{
		to_ret=tmp;
	}
	
	while (tmp!=players_tree)
	{
		tmp=FindInorderSuccessor(tmp);
		if (tmp->evidence>to_ret->evidence)
		{
		to_ret=tmp;
		}
		
	}
	return to_ret;
	

}

Task *split_task(Task* root,int counter);
/**
 * @brief Give Away Work
 *
 * @param pid_1 The existing crewmate's id
 *
 * @param pid_2 The new crewmate's pid
 *
 * @return 1 on success
 *         0 on failure
 */
int give_work(int pid_1, int pid_2)
{
	//check for the first player
	Player *tmp_player= players_tree;
	while (tmp_player->pid!=-1)
	{
		//if found
		if (tmp_player->pid==pid_1)
		{
			break;
		}
		
		if(tmp_player->pid>pid_1){
			tmp_player=tmp_player->lc;
		}else
		{
			tmp_player=tmp_player->rc;
		}
	}
	if (tmp_player->pid==-1)
	{
		return 0;
	}
	//looks for the pid_2 player
	Player *tmp_player2= players_tree;
	while (tmp_player2->pid!=-1)
	{
		//if found
		if (tmp_player2->pid==pid_2)
		{
			break;
		}
		
		if(tmp_player2->pid>pid_2){
			tmp_player2=tmp_player2->lc;
		}else
		{
			tmp_player2=tmp_player2->rc;
		}
	}
	//there isnt supposed to be a player with pid 2
	if(tmp_player2->pid!=-1){
		return 0;
	}
	register_player(pid_2,0);
	tmp_player2= players_tree;
	while (tmp_player2->pid!=-1)
	{
		//if found
		if (tmp_player2->pid==pid_2)
		{
			break;
		}
		
		if(tmp_player2->pid>pid_2){
			tmp_player2=tmp_player2->lc;
		}else
		{
			tmp_player2=tmp_player2->rc;
		}
	}

	Task *tmp_task = tmp_player->tasks;
	int count_of_task = 0;
	//counts the tasks
	while (tmp_task!=NULL)
	{
		count_of_task+=1+tmp_task->lcnt;
		tmp_task=tmp_task->rc;
	}
	//if there are no tasks
	if (count_of_task==0)
	{
		return 0;
	}
	//if there is one task its considered success
	if (count_of_task==1)
	{
		print_double_tree();
		return 1;
	}
	tmp_player2->tasks=split_task(tmp_player->tasks,count_of_task/2);

	print_double_tree();
	return 1;
}
Task *split_task(Task* root,int counter){
	//base hit
	if (root==NULL){return NULL;}

	Task *p1 ;
	if (counter-root->lcnt==0)
	{
		p1=root->lc;
		root->lc=NULL;
		//TESTING THINGS================================================================================================
		root->lcnt=0;
		Task * test_barethika = root->lc;
	
		while (test_barethika!=NULL)
		{
			root->lcnt+= test_barethika->lcnt+1;
			test_barethika=test_barethika->rc;
		}
		//END OF TESTING================================================================================================
		return p1;
	}else if (counter - root->lcnt==1){
		
		p1 = root->rc;
		root->rc=NULL;
		//TESTING THINGS================================================================================================
		root->lcnt=0;
		Task * test_barethika = root->lc;
	
		while (test_barethika!=NULL)
		{
			root->lcnt+= test_barethika->lcnt+1;
			test_barethika=test_barethika->rc;
		}
		//END OF TESTING================================================================================================
		return p1;

	}else if (counter - root->lcnt >0){
		if (root->rc!=NULL)
		{
			Task*temp;
			temp=split_task(root->rc,counter-root->lcnt-1);
			p1 = root->rc;
			root->rc=temp;
			
		}else
		{
			p1=root;
		}
	}else{
		Task*temp;
		temp=split_task(root->lc,counter);
		p1= root->lc;
		root->lc=temp;
	}
	//TESTING THINGS
	root->lcnt=0;
	Task * test_barethika = root->lc;
	
	while (test_barethika!=NULL)
	{
		root->lcnt+= test_barethika->lcnt+1;
		test_barethika=test_barethika->rc;
	}
	//END OF TESTING
	return p1;
	
}


/**
 * @brief Terminate
 *
 * @return 1 on success
 *         0 on failure
 */
void how_many_alien(Player *curr);
int aliens_total;
int crewmates_total;
int Terminate()
{
	if(completed_tasks_pq.size==max_tasks_g){
		cout <<"Crewmates win"<<endl;
		return 1;
	}
	aliens_total=0;
	crewmates_total=0;
	how_many_alien(players_tree);

	if (aliens_total>=crewmates_total)
	{
		cout << "Aliens win."<<endl;
		return 1;
	}else if (aliens_total==0)
	{
		cout << "Crewmates win"<<endl;
		return 1;
	}
	

	
	

	return 0;
}
void how_many_alien(Player *curr){
	if (curr->pid==-1){return ;}

	how_many_alien(curr->lc);
	if (curr->is_alien==0)
	{
		crewmates_total++;
	}else if (curr->is_alien==1){
		aliens_total++;
	}
	how_many_alien(curr->rc);
	return ;
	
}
/**
 * @brief Print Players
 *
 * @return 1 on success
 *         0 on failure
 */

int print_players()
{
	cout << "Players = ";
	InOrder(players_tree);
	cout << endl;
	return 1;
}

void InOrder(Player *tmp)
{
	if (tmp->pid == -1)
		return;
	InOrder(tmp->lc);
	cout << "<" << tmp->pid << " , " << tmp->is_alien << ">";
	InOrder(tmp->rc);
}

/**
 * @brief Print Tasks
 *
 * @return 1 on success
 *         0 on failure
 */
int print_tasks()
{
	int x = 0;
	while (x != max_tasks_g)
	{
		cout << "Index " << x;
		//if the cells is empty
		if (general_tasks_ht.tasks[x] == NULL)
		{
			cout << " is empty" << endl;
		}
		else
		{
			//if it isnt it searches the list one by one and prints them all
			HT_Task *tmp = general_tasks_ht.tasks[x];
			while (tmp != NULL)
			{
				cout << " <" << tmp->tid << "," << tmp->difficulty << ">";
				tmp = tmp->next;
			}
			cout << endl;
		}

		x++;
	}

	return 1;
}

/**
 * @brief Print Priority Queue
 *
 * @return 1 on success
 *         0 on failure
 */
int print_pq()
{
	cout << "Completed tasks ";
	for (int i = 0; i < completed_tasks_pq.size; i++)
	{
		cout <<"<"<< completed_tasks_pq.tasks[i].tid <<","<<completed_tasks_pq.tasks[i].difficulty << ">";
	}
	cout << endl;
	return 1;
}

/**
 * @brief Print Players & Task tree
 *
 * @return 1 on success
 *         0 on failure
 */
int print_double_tree()
{
	InOrder_players(players_tree);
	return 1;
}
void InOrder_players(Player *tmp)
{
	if (tmp->pid == -1)return;
	InOrder_players(tmp->lc);
	
	cout << "<" << tmp->pid << " , " << tmp->is_alien << ">= ";
	if (tmp->tasks==NULL)
	{
		cout << "<Empty task>" <<endl;
	}else
	{
		InOrder_players_tasks(tmp->tasks);	
		cout << endl;
	}
	InOrder_players(tmp->rc);
}
void InOrder_players_tasks(Task *tmp)
{
	if (tmp == NULL)return;
	InOrder_players_tasks(tmp->lc);
	cout << "<" << tmp->tid << " , " << tmp->difficulty << ">";
	InOrder_players_tasks(tmp->rc);
}

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */

int free_all(void)
{
	
	return 1;
}

#define BUFFER_SIZE 1024 /* Maximum length of a line in input file */

/* Uncomment the following line to enable debugging prints 
 * or comment to disable it */
#define DEBUG
#ifdef DEBUG
#define DPRINT(...) fprintf(stderr, __VA_ARGS__);
#else /* DEBUG */
#define DPRINT(...)
#endif /* DEBUG */

/**
 * @brief The main function
 *
 * @param argc Number of arguments
 * @param argv Argument vector
 *
 * @return 0 on success
 *         1 on failure
 */
int main(int argc, char **argv)
{
	FILE *fin = NULL;
	char buff[BUFFER_SIZE], event = '\0';

	/* Check command buff arguments */
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <input_file> <>\n", argv[0]);
		return EXIT_FAILURE;
	}

	/* Open input file */
	if ((fin = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "\n Could not open file: %s\n", argv[1]);
		perror("Opening test file\n");
		return EXIT_FAILURE;
	}

	// Read max enemy soldiers' number
	fgets(buff, BUFFER_SIZE, fin);
	sscanf(buff, "%d", &max_tasks_g);
	DPRINT("Max number of tasks: %d\n", max_tasks_g)

	// Read max enemy soldiers' ID
	fgets(buff, BUFFER_SIZE, fin);
	sscanf(buff, "%d", &max_tid_g);
	DPRINT("Max task tid: %d\n", max_tid_g)

	/* Initializations */
	initialize();

	/* Read input file buff-by-buff and handle the events */
	while (fgets(buff, BUFFER_SIZE, fin))
	{

		DPRINT("\n>>> Event: %s", buff);

		switch (buff[0])
		{

		/* Comment */
		case '#':
			break;

		/* Register Player
		 * P <pid> <is_alien> */
		case 'P':
		{
			int pid;
			int is_alien;
			sscanf(buff, "%c %d %d", &event, &pid, &is_alien);
			DPRINT("%c %d %d\n", event, pid, is_alien);

			if (register_player(pid, is_alien))
			{
				DPRINT("P %d %d succeeded\n", pid, is_alien);
			}
			else
			{
				fprintf(stderr, "P %d %d failed\n", pid, is_alien);
			}

			break;
		}

		/* Insert Task
		 * T <tid> <difficulty>  */
		case 'T':
		{
			int tid, difficulty;

			sscanf(buff, "%c %d %d", &event, &tid, &difficulty);
			DPRINT("%c %d %d\n", event, tid, difficulty);

			if (insert_task(tid, difficulty))
			{
				DPRINT("%c %d %d succeded\n", event, tid, difficulty);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, tid, difficulty);
			}

			break;
		}

		/* Distribute Tasks
		 * D */
		case 'D':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (distribute_tasks())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Implement Task
		 * I <pid> <tid> */
		case 'I':
		{
			int pid, tid;

			sscanf(buff, "%c %d %d", &event, &pid, &tid);
			DPRINT("%c %d %d \n", event, pid, tid);

			if (implement_task(pid, tid))
			{
				DPRINT("%c %d %d succeeded\n", event, pid, tid);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, pid, tid);
			}

			break;
		}

		/* Eject Player
		 * E <pid_1> <pid_2>*/
		case 'E':
		{
			int pid_1, pid_2;

			sscanf(buff, "%c %d %d", &event, &pid_1, &pid_2);
			DPRINT("%c %d %d\n", event, pid_1, pid_2);

			if (eject_player(pid_1, pid_2))
			{
				DPRINT("%c %d %d succeeded\n", event, pid_1, pid_2);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, pid_1, pid_2);
			}

			break;
		}

		/* Witness Ejection
		 * W <pid> <pid_a> <number_of_witnesses>
		 */
		case 'W':
		{
			int pid_1, pid_2, pid_a, number_of_witnesses;

			sscanf(buff, "%c %d %d %d %d", &event, &pid_1, &pid_2, &pid_a, &number_of_witnesses);
			DPRINT("%c %d %d %d %d\n", event, pid_1, pid_2, pid_a, number_of_witnesses);

			if (witness_eject(pid_1, pid_2, pid_a, number_of_witnesses))
			{
				DPRINT("%c %d %d %d %d succeded\n", event, pid_1, pid_2, pid_a, number_of_witnesses);
			}
			else
			{
				fprintf(stderr, "%c %d %d %d %d failed\n", event, pid_1, pid_2, pid_a, number_of_witnesses);
			}

			break;
		}

		/* Sabotage
		 * S <number_of_tasks> <pid> */
		case 'S':
		{
			int number_of_tasks, pid;

			sscanf(buff, "%c %d %d\n", &event, &number_of_tasks, &pid);
			DPRINT("%c %d %d\n", event, number_of_tasks, pid);

			if (sabotage(number_of_tasks, pid))
			{
				DPRINT("%c %d %d succeeded\n", event, number_of_tasks, pid);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, number_of_tasks, pid);
			}

			break;
		}

		/* Vote
		 * V <pid_1> <pid_2> <vote_evidence> */
		case 'V':
		{
			int pid_1, pid_2, vote_evidence;

			sscanf(buff, "%c %d %d %d\n", &event, &pid_1, &pid_2, &vote_evidence);
			DPRINT("%c %d %d %d\n", event, pid_1, pid_2, vote_evidence);

			if (vote(pid_1, pid_2, vote_evidence))
			{
				DPRINT("%c %d %d %d succeeded\n", event, pid_1, pid_2, vote_evidence);
			}
			else
			{
				fprintf(stderr, "%c %d %d %d failed\n", event, pid_1, pid_2, vote_evidence);
			}

			break;
		}

		/* Give Away Work
		 * G <pid_1> <pid_2> */
		case 'G':
		{
			int pid_1, pid_2;

			sscanf(buff, "%c %d %d", &event, &pid_1, &pid_2);
			DPRINT("%c %d %d\n", event, pid_1, pid_2);

			if (give_work(pid_1, pid_2))
			{
				DPRINT("%c %d %d succeeded\n", event, pid_1, pid_2);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, pid_1, pid_2);
			}

			break;
		}

		/* Terminate
		 * F */
		case 'F':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (Terminate())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Print Players
		 * X */
		case 'X':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (print_players())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Print Tasks
		 * Y */
		case 'Y':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (print_tasks())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Print Priority Queue
		 * Z */
		case 'Z':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (print_pq())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Print Players & Tasks tree
		 * F */
		case 'U':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (print_double_tree())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Empty line */
		case '\n':
			break;

		/* Ignore everything else */
		default:
			DPRINT("Ignoring buff: %s \n", buff);

			break;
		}
	}

	free_all();
	return (EXIT_SUCCESS);
}
