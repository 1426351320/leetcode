class Solution {
public:
	int rectCover(int number);
};

int Solution::rectCover(int number) 
{
	int SubQuestion[2];
	SubQuestion[0] = 1;
	SubQuestion[1] = 2;

	switch (number)
	{
    case 0:
		return 0;
	case 1:
		return SubQuestion[0];
	case 2:
		return SubQuestion[1];
	default:
		for (int i(3); i <= number; i++)
		{
			SubQuestion[(i - 1) % 2] = SubQuestion[0] + SubQuestion[1];
			if (i == number)
				return SubQuestion[(i - 1) % 2];
		}
	}
    return 1;
}