#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define TXT 1024
#define WORD 30

char word[WORD];
char txt[TXT];

void writeWord(){
    char c = 0;
    printf("Write Word:");
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
    printf("Write: ");
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