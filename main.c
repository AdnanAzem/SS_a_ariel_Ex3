#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define TXT 1024
#define WORD 30

char word[WORD];
char txt[TXT];


// Q1
void writeWord(){
    
    char c = 0;
    scanf("%c", &c);
    int i = 0;
    for (; c != ' ' && c != '\t' && c != '\n' && i < WORD; i++){
        word[i] = c;
        scanf("%c", &c);
    }
    word[i] = '\0';
}

void writeTxt(){
    
    char c = 0;
    scanf("%c", &c);
    int i;
    for (i=0; c != '~' && i < TXT; i++){
        txt[i] = c;
        scanf("%c", &c);
    }
    txt[i] = '\0';
}

int CharToNum(char c){
    int num;
    int cNum = (int)c;
    if(c>='A' && c<='Z'){
        num = cNum-64;
        }
    else if(c>='a' && c<='z'){
        num = cNum-96;
        }
    else{
        num = 0;
        }
    return num;
}

int CalcWord(char *c){
    int ans=0;
    for (int i = 0; i < strlen(c); i++) {
        int s = CharToNum(c[i]);
        ans = ans+s;
    }
    return ans;
    
}

int GematriaWord(){
    int ans=0;
    int i=0;
    while (word[i] != '\0'){
        int s = CharToNum(word[i]);
        ans = ans + s;
        i++;
    }
    return ans;
}

void GematriaSentence(){
    int GWord = GematriaWord();
    printf("Gematria Sequences: ");
    int checkToPrint = 0;
    int i = 0;
    while (txt[i] != '\0')
    {
        int sum = 0;
        int j = i;
        if ((txt[i] >= 'a' && txt[i] <= 'z') || (txt[i] >= 'A' && txt[i] <= 'Z'))
        {
            while (txt[j] != '\0' && sum < GWord)
            {
                if (txt[j] >= 'a' && txt[j] <= 'z')
                {
                    sum += CharToNum(txt[j]);
                }
                else if (txt[j] >= 'A' && txt[j] <= 'Z')
                {
                    sum += CharToNum(txt[j]);
                }
                j++;
            }
            j--;
            if (sum == GWord)
            {
                if (checkToPrint)
                {
                    printf("~");
                }
                for (int k = i; k <= j; k++)
                {
                    printf("%c", txt[k]);
                }
                checkToPrint++;
            }
        }
        i++;
    }
    printf("\n");
}


//Q2
char *AtbashWord(){
    int i = 0;
    char *ans = malloc(sizeof(char) * WORD);
    if (ans == NULL)
    {
        printf("Memory Error");
        exit(0);
    }
    while (word[i] != '\0' || i <= WORD)
    {
        if(word[i] >= 'a' && word[i] <= 'z'){
            ans[i] = 'z' + 'a' - word[i];
        }
        else if(word[i] >= 'A' && word[i] <= 'Z'){
            ans[i] = 'Z' + 'A' - word[i];
        }
        else{
            ans[i] = word[i];
        }
        i++;
    }
    return ans;
}

char *ReverseAtbashWord(char *revWord){
    char *ans = malloc(sizeof(char) * WORD);
    int end = 0;
    while (revWord[end] != '\0')
    {
        ++end;
    }
    for (int i = 0; i < end; i++)
    {
        ans[i] = revWord[end - i - 1];
    }
    ans[end] = '\0';
    return ans;
}
int check(int index, char *Rword, char *txt) {
	int i = 0,count=0;
	while (txt[index] != 0) {
		if (Rword[i]!='\0'&&Rword[i] == txt[index]) {
			count++;
			i++;
			index++;
		}
		else {
			break;
			count = 0;
		}
	}
	return count;
}

void AtbashSentence(){
    printf("Atbash Sequences: ");
    char *atbash = AtbashWord();
    char *revAtbash = ReverseAtbashWord(atbash);
    int i = 0;
    int checkToPrint = 0;
    while (txt[i] != '\0')
    {
        if(txt[i] == atbash[0]){
            int count=check(i,atbash,txt);
            if(count==strlen(word)){
                    if(checkToPrint){
                        printf("~");
                    }
                while(count!=0){
                    
                    printf("%c",txt[i]);
                    i++;
                    count--;
                }
                checkToPrint++;
            }
            
        }
        else if(txt[i] == revAtbash[0]){
             int count=check(i,revAtbash,txt);
            if(count==strlen(word)){
                if(checkToPrint){
                    printf("~");
                }
                while(count!=0){
                    printf("%c",txt[i]);
                    i++;
                    count--;
                }
                checkToPrint++;
            }

        }
    i++;
    }
    printf("\n"); 
}



// Q3
void swap(char *a, char *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void Sort(char arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void removeStr(char* str, char c){
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] == c){
            for(int k = i; k < len; k++){
                str[k] = str[k + 1];
            }
            len--;
            i--;
        }
    }
}

void AnagramSentence(){
    printf("Anagram Sequences: ");
    int checkToPrint = 0;
    char wSorted[strlen(word)];
    strcpy(wSorted, word);
    Sort(wSorted, strlen(wSorted));
    for (int i=0; i<= strlen(txt); i++) 
    {
        if ((txt[i]!=' ') )
        {
            for (int j = i; j <= strlen(txt); j++) 
            {
                int len = j - i + 1;
                char checkWord[len + 1];
                int counter = 0;
                for (int t = i; t < j; t++) 
                {
                    checkWord[counter] = txt[t];
                    counter++;
                }
                checkWord[counter] = '\0';
                char copyWord[strlen(checkWord)];
                strcpy(copyWord, checkWord);
                Sort(copyWord, strlen(copyWord));
                removeStr(copyWord, ' ');
                int comp = strcmp(copyWord, wSorted);
                if (comp == 0) 
                {
                    if (checkToPrint) 
                    {
                        printf("~");
                    }
                    for (int k = 0; k < strlen(checkWord); k++) 
                    {
                        printf("%c", checkWord[k]);
                    }
                    checkToPrint++;
                    break;
                }
            }
        }
    }
}


int main()
{
    writeWord();
    writeTxt();
    GematriaSentence();
    AtbashSentence();
    AnagramSentence();
    return 0;
}
