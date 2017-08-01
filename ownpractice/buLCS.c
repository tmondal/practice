#include <stdio.h>
#include <string.h>




int bottmupLCS(char *str1, char *str2, int m, int n){

	int matrix[m+1][n+1];
	int i,j;

	for (i = 0; i <= m; ++i)
	{
		for (j = 0; j <= n; ++j)
		{
			if (i == 0 || j == 0)
			{
				matrix[i][j] = 0;
			}

			else if (str1[i-1] == str2[j-1])
			{
				matrix[i][j] = 1 + matrix[i-1][j-1];
			}
			else{
				if (matrix[i][j-1] > matrix[i-1][j])
				{
					matrix[i][j] = matrix[i][j-1];
				}else{
					matrix[i][j] = matrix[i-1][j];
				}
			}
		}
	}

	printf("Lcs table: \n");
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}

	return matrix[m][n];
}


int main(int argc, char const *argv[])
{
	char string1[] = "abkc";
	char string2[] = "bklg";

	int len1 = strlen(string1);
	int len2 = strlen(string2);
	int length = bottmupLCS(string1,string2,len1,len2);
	printf("Lcs length: %d\n", length);

	return 0;
}