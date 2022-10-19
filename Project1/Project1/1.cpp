#include <iostream>
#include <string>
#include <random>
#include <time.h>

char Inputcom();
void Outputmat(int[3][3]);
void Randommat(int[3][3], int[3][3]);

int main()
{
	char input{};
	int Amat[3][3]{};
	int Bmat[3][3]{};
	int Cmat[3][3]{};
	int Atmat[3][3]{};
	int Btmat[3][3]{};
	int A4mat[4][4]{};
	int B4mat[4][4]{};
	int determinant{};
	srand((unsigned int)time(NULL));

	Randommat(Amat, Bmat);

	std::cout << "A:" << std::endl;
	Outputmat(Amat);
	std::cout << std::endl << "B:" << std::endl;
	Outputmat(Bmat);

	while (true)
	{
		input = Inputcom();

		switch (input)
		{
		case 'q':
			return 0;

		case 's':
			Randommat(Amat, Bmat);

			std::cout << "A:" << std::endl;
			Outputmat(Amat);
			std::cout << std::endl;
			std::cout << "B:" << std::endl;
			Outputmat(Bmat);

			break;

		case 'm':
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Cmat[i][j] = 0;
					for (int k = 0; k < 3; k++)
					{
						Cmat[i][j] += Amat[i][k] * Bmat[k][j];
					}
				}
			}
			Outputmat(Amat);
			std::cout << std::endl << "*" << std::endl;
			Outputmat(Bmat);
			std::cout << std::endl << "=" << std::endl;
			Outputmat(Cmat);
			break;

		case 'a':
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					Cmat[i][j] = Amat[i][j] + Bmat[i][j];
			Outputmat(Amat);
			std::cout << std::endl << "+" << std::endl;
			Outputmat(Bmat);
			std::cout << std::endl << "=" << std::endl;
			Outputmat(Cmat);
			break;

		case 'd':
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					Cmat[i][j] = Amat[i][j] - Bmat[i][j];
			Outputmat(Amat);
			std::cout << std::endl << "-" << std::endl;
			Outputmat(Bmat);
			std::cout << std::endl << "=" << std::endl;
			Outputmat(Cmat);
			break;

		case 'r':
			determinant = {};
			for (int i = 0; i < 3; ++i)
				determinant += Amat[0][i] * (Amat[1][(i + 1) % 3] * Amat[2][(i + 2) % 3]
					- Amat[1][(i + 2) % 3] * Amat[2][(i + 1) % 3]);

			std::cout << std::endl << "A 행렬식: " << determinant << std::endl;

			determinant = {};
			for (int i = 0; i < 3; ++i)
				determinant += Bmat[0][i] * (Bmat[1][(i + 1) % 3] * Bmat[2][(i + 2) % 3]
					- Bmat[1][(i + 2) % 3] * Bmat[2][(i + 1) % 3]);

			std::cout << std::endl << "B 행렬식: " << determinant << std::endl;
			break;

		case 't':
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (i == j)
						Atmat[i][j] = Amat[i][j];
					else
						Atmat[i][j] = Amat[j][i];
				}
			}

			std::cout << std::endl << "A 전치행렬:" << std::endl;
			Outputmat(Atmat);

			determinant = {};
			for (int i = 0; i < 3; ++i)
				determinant += Atmat[0][i] * (Atmat[1][(i + 1) % 3] * Atmat[2][(i + 2) % 3]
					- Atmat[1][(i + 2) % 3] * Atmat[2][(i + 1) % 3]);

			std::cout << std::endl << "행렬식: " << determinant << std::endl;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (i == j)
						Btmat[i][j] = Bmat[i][j];
					else
						Btmat[i][j] = Bmat[j][i];
				}
			}

			std::cout << std::endl << "B 전치행렬:" << std::endl;
			Outputmat(Btmat);

			determinant = {};
			for (int i = 0; i < 3; ++i)
				determinant += Btmat[0][i] * (Btmat[1][(i + 1) % 3] * Btmat[2][(i + 2) % 3]
					- Btmat[1][(i + 2) % 3] * Btmat[2][(i + 1) % 3]);

			std::cout << std::endl << "행렬식: " << determinant << std::endl;

			break;

		case 'h':
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					A4mat[i][j] = Amat[i][j];
				}
			}

			for (int i = 0; i < 3; i++)
			{
				A4mat[i][3] = 0;
				A4mat[3][i] = 0;
			}
			A4mat[3][3] = 1;

			std::cout << std::endl << "A 행렬 4x4 변환:" << std::endl;

			for (int i = 0; i < 4; i++)
			{
				std::cout << "|\t";
				for (int j = 0; j < 4; j++)
				{
					std::cout << A4mat[i][j] << "\t";
				}
				std::cout << "|" << std::endl;
			}

			determinant = {};

			for (int i = 0; i < 4; ++i)
				determinant += A4mat[0][i] * (A4mat[1][(i + 1) % 4] * A4mat[2][(i + 2) % 4] * A4mat[3][(i + 3) % 4]
					- A4mat[1][(i + 3) % 4] * A4mat[2][(i + 2) % 4] * A4mat[3][(i + 1) % 4]);

			std::cout << std::endl << "행렬식: " << determinant << std::endl;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					B4mat[i][j] = Bmat[i][j];
				}
			}

			for (int i = 0; i < 3; i++)
			{
				B4mat[i][3] = 0;
				B4mat[3][i] = 0;
			}
			B4mat[3][3] = 1;

			std::cout << std::endl << "B 행렬 4x4 변환:" << std::endl;

			for (int i = 0; i < 4; i++)
			{
				std::cout << "|\t";
				for (int j = 0; j < 4; j++)
				{
					std::cout << B4mat[i][j] << "\t";
				}
				std::cout << "|" << std::endl;
			}

			determinant = {};

			for (int i = 0; i < 4; ++i)
				determinant += B4mat[0][i] * (B4mat[1][(i + 1) % 4] * B4mat[2][(i + 2) % 4] * B4mat[3][(i + 3) % 4]
					- B4mat[1][(i + 3) % 4] * B4mat[2][(i + 2) % 4] * B4mat[3][(i + 1) % 4]);

			std::cout << std::endl << "행렬식: " << determinant << std::endl;

			break;
		}

	}
}

char Inputcom()
{
	std::cout << std::endl << "Input command: ";
	char input;
	std::cin >> input;
	return input;
}

void Outputmat(int a[3][3])
{
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "|\t";
		for (int j = 0; j < 3; j++)
		{
			std::cout << a[i][j] << "\t";
		}
		std::cout << "|" << std::endl;
	}
}

void Randommat(int a[3][3], int b[3][3])
{
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[i][j] = rand() % 2;
			b[i][j] = rand() % 2;
		}
	}
}