/*
 * LLSE.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: Percy
 */

#include "Node.hpp"
#include "LLSE.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
using namespace std;

LLSE::LLSE(){
	first =	last = NULL;
	size = wordcount =0;
}

void LLSE::printLL(){
	Node *temp = first;
	while(temp != NULL){
		cout << temp->word << " \n     count:" << temp->count << endl;
		temp = temp->next;
	}
	cout << "-----------------\n" << "Size:" << size << endl;
	cout << "WordCount:" << wordcount <<endl;
}

void LLSE::addFirst(string x){
	first = new Node(x);
	last = first;
	size ++;
	wordcount += first->count;
}

void LLSE::addAtFirst(string x){
	Node *nfirst = new Node(x);
	wordcount += nfirst->count;
	first->prev = nfirst;
	nfirst->next = first;
	first = nfirst;
	size ++;
}

void LLSE::push(string x){
	Node *nlast = new Node(x);
	wordcount += nlast->count;
	last->next = nlast;
	nlast->prev = last;
	last = nlast;
	size ++;
}

Node *LLSE::findInsert(string x){
	Node *temp = first;
	while(temp != NULL){
		if(temp->word == x) return temp;

		int i = 0;
		while(temp->word[i]){
			if(int(temp->word[i]) > int(x[i])) return temp->prev;
			if(int(temp->word[i]) < int(x[i])) break;
			if(int(temp->word[i]) == int(x[i])) i++;
		}
		temp = temp->next;
	}
	return last;
}

void LLSE::insertUnique(string x){

	if(!first) {
		addFirst(x);
		return;
	}

	Node *temp = findInsert(x);
	if(temp == NULL) {
			addAtFirst(x);
			return;
	}

	if(temp->word == x) {
		temp->count ++;
		wordcount ++;
		return;
	}

	if(temp == last){
		push(x);
		return;
	}

	Node *nnode = new Node(x);
	nnode->next = temp->next;
	nnode->prev = temp;
	temp->next->prev = nnode;
	temp->next = nnode;
	size = size +1;
	wordcount += nnode->count;

}

void LLSE::normalizeCounts(){
	Node *curr = first;
	while(curr){
		curr->count = curr->count/wordcount;
		curr = curr->next;
	}
	wordcount = 1.00f;
}

string LLSE::remFirst(){
	string g = first->word;
	wordcount -= first->count;
	first = first->next;
	first->prev->next =NULL;
	delete first->prev;
	first->prev = NULL;
	size --;
	return g;
}

string LLSE::pop(){
	string g = last->word;
	wordcount -= last->count;
	last = last->prev;
	last->next->prev = NULL;
	delete last->next;
	last->next = NULL;
	size --;
	return g;
}

string LLSE::remNext(Node *n){
	Node *temp = n->next;
	wordcount -= temp->count;
	string g = temp->word;
	n->next = temp->next;
	temp->next->prev = n;
	temp->prev = temp->next = NULL;
	delete temp;
	size --;
	return g;
}

void LLSE::eliminateLowWords(){
	Node *temp = first;
	while(temp != NULL){
		if(temp->count < 0.004f){
			if(temp == first){
				remFirst();
				temp = first;
			}else if(temp == last){
				pop();
				temp = NULL;
			}else{
				temp = temp->prev;
				remNext(temp);
			}
		}else{
			temp = temp -> next;
		}
	}
}

