#include <stdio.h>

int main(void)
{
	int i, j;
    char word[100] = { 0 };
    scanf("%s", word);
    for (i = 97; i <= 122; i++) {
        j = 0;
        while (word[j] != 0) {
            if (word[j] == (char)i) break;
            j++;
        }
        if (word[j] == (char)i) printf("%d ", j);
        else printf("-1 ");
    }
}
