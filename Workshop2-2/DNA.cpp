#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "DNA.h"
#include "cStrTools.h"
using namespace std;
namespace sdds {
	
	int* indexes = nullptr;
	findDNA* dptr = nullptr;
	int allocation_size;
	int numOfStrands;
	int arraySize;
	const int numberOfStrands = 12345;
	fileDNA f[numberOfStrands];
	int i = 0;
	FILE* fptr = NULL;
	bool beginSearch(const char* filename)
	{
		
		cout << "DNA search program" << endl;
		arraySize = 80;
		numOfStrands = 0;
		allocation_size = 80;
		
		
		 fptr = fopen(filename, "r");
		if (fptr) {
			
			while ((fscanf(fptr, "%[^,],%s\n", f[i].digit, f[i].strand)) != EOF)
			{

				i++;
			}
			fclose(fptr);
			 
			return true;
			
		}
		else
			return false;
	}

	bool read(const char* subDNA)
	{
		
		indexes = new int[arraySize];
		bool result = false;
		for (int j = 0; j < i; j++)
		{
			if (strStr(f[j].strand, subDNA) != nullptr)
			{
				result = true; 
				
				if (numOfStrands == arraySize)
				{
					int* tptr= new int[arraySize + allocation_size];
					for (int k = 0; k < numOfStrands; k++) {
						tptr[k] = indexes[k];
					}
					delete[] indexes;
				indexes=tptr;
				delete[] tptr;
					arraySize = numOfStrands + allocation_size;
				}
			indexes[numOfStrands++]=j;
			
			}
		}
		if (result) 
		{
			
			dptr = new findDNA[numOfStrands];
			for (int j = 0; j < numOfStrands; j++)
			{
				int index = indexes[j];
				dptr[j].ids = atoi(f[index].digit);
				dptr[j].matched_strands = new char[strLen(f[index].strand) + 1];
				strCpy(dptr[j].matched_strands, f[index].strand);

			}
		}
		delete[] indexes;
		return result;
	}


	void sort()
	{
		for (int j = 0; j < numOfStrands; j++)
		{
			
			for (int k = 0; k < numOfStrands; k++) {
				
				
				
				if(dptr[j].ids< dptr[k].ids)
				{
					int ptr= dptr[j].ids;
					dptr[j].ids = dptr[k].ids;
					dptr[k].ids = ptr;
					
					char* tptr = new char[strLen(dptr[j].matched_strands)];
					strCpy(tptr, dptr[j].matched_strands);
					delete[] dptr[j].matched_strands;

					dptr[j].matched_strands = new char[strLen(dptr[k].matched_strands)];
					strCpy(dptr[j].matched_strands, dptr[k].matched_strands);
					delete[] dptr[k].matched_strands;

					dptr[k].matched_strands = new char[strLen(tptr)];
					strCpy(dptr[k].matched_strands,tptr);
					delete[] tptr;
				}
			}
		}
	}
	
	void displayMatches()
	{
		
		cout << numOfStrands << " matches found:"<< endl;
		for (int h = 0; h< numOfStrands; h++)
		{
			cout << h+1<< ") " << dptr[h].ids << ":" << endl;
			cout << dptr[h].matched_strands << endl;
	cout << "======================================================================" << endl;
		}
	}

	void deallocate()
	{
		
			//delete[] indexes;
			//indexes = nullptr;
			delete[] dptr;
			dptr = nullptr;
			
		
		numOfStrands = 0;
		arraySize = 80;
	}

	void endSearch()
	{
		
		
		cout << "DNA Search Program Closed." << endl;
	}
}
