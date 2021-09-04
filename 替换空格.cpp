class Solution
{
public:
	void replaceSpace(char *str, int length);
};

void Solution::replaceSpace(char *str, int length)
{
	int SpaceNum(0);
	int OriginLength(0);
	for (;str[OriginLength] != '\0'; OriginLength++)
	{
		if (str[OriginLength] == ' ')
			SpaceNum++;
	}
	OriginLength ++;

 	for (int i(OriginLength - 1); i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			str[i + 2 * SpaceNum] = '0';
			str[i + 2 * SpaceNum - 1] = '2';
			str[i + 2 * SpaceNum - 2] = '%';
			SpaceNum--;
			continue;
		}
		str[i + 2 * SpaceNum] = str[i];
	}
}