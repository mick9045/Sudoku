#include "GameField.h"
#include <time.h>
#include <stdlib.h>
#include <exception>
#include <vector>
namespace Sudoku
{
	GameField::GameField()
	{
		Reset();
		srand(time(0));
	}

	GameField::~GameField()
	{
	}

	int GameField::Get(int x, int y)
	{
		return _field[y][x];
	}

	int GameField::Set(int x, int y, int value)
	{
		return _field[y][x] = value;
	}

	bool GameField::IsDeleted(int x, int y)
	{
		return _deleted[y][x];
	}

	bool GameField::IsSolved()
	{
		int target = 45;
		int sum = 0;
		for (int i = 0; i < Size(); i++)
		{
			for (int j = 0; j < Size(); j++)
			{
				sum += _field[i][j];
			}
			if (sum != target)
			{
				return false;
			}
			sum = 0;
		}

		for (int i = 0; i < Size(); i++)
		{
			for (int j = 0; j < Size(); j++)
			{
				sum += _field[j][i];
			}
			if (sum != target)
			{
				return false;
			}
			sum = 0;
		}

		int counter = 0;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++, counter++)
			{
				sum += _field[j / 3 + (i / 3) * 3][j % 3 + (i % 3) * 3];
			}
		
			if (counter == 8)
			{
				if (sum != target)
					return false;
			}
			counter = 0;
			sum = 0;
		}

		return true;
	}

	void GameField::Initialize()
	{
		GenerateField();
		for (int i = 0; i < 10; i++)
		{
			int mix = rand() % 5;
			switch (mix)
			{
			case 0:
				Transpose();
				break;
			case 1:
				SwapColumnsBlock();
				break;
			case 2:
				SwapColumnsGlobal();
				break;
			case 3:
				SwapRowsBlock();
				break;
			case 4:
				SwapRowsGlobal();
				break;

			}
		}
		RemoveRandomCells();
	}

	void GameField::GenerateField()
	{
		for (int i = 0; i < Size(); i++)
		{
			for (int j = 0; j < Size(); j++)
			{
				_field[i][j] = (i * _n + i / _n + j) % (_n * _n) + 1;
			}
		}
	}

	void GameField::RemoveRandomCells()
	{
		int removeCount = 4;
		for (int i = 0; i < Size(); i++)
		{
			for (int j = 0; j < removeCount; j++)
			{
				int randomX = rand() % Size();
				int exitCounter = 0;
				while (_deleted[i][randomX] == true)
				{
					randomX++;
					exitCounter++;
					if (randomX >= Size())
					{
						randomX %= Size();
					}
					if (exitCounter >= Size())
					{
						return;
					}
				}
				_field[i][randomX] = 0;
				_deleted[i][randomX] = true;
			}
		}
	}

	void GameField::Transpose()
	{
		for (int i = 1; i < Size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				SwapCells(i, j, j, i);
			}
		}
	}

	void GameField::SwapRowsBlock()
	{
		int block;
		int offset1;
		int offset2;
		int line1;
		int line2;

		block = rand() % _n;
		offset1 = rand() % _n;

		line1 = block * _n + offset1;

		offset2 = rand() % _n;
		if (offset2 == offset1)
		{
			offset2++;
			offset2 %= _n;
		}

		line2 = block * _n + offset2;

		SwapLines(line1, line2);
	}

	void GameField::SwapColumnsBlock()
	{
		Transpose();
		SwapRowsBlock();
		Transpose();
	}

	void GameField::SwapRowsGlobal()
	{
		int block1;
		int block2;
		int line1;
		int line2;

		block1 = rand() % _n;
		block2 = rand() % _n;

		if (block2 == block1)
		{
			block2++;
			block2 %= _n;
		}

		for (int i = -0; i < _n; i++)
		{
			line1 = block1 * _n + i;
			line2 = block2 * _n + i;
			SwapLines(line1, line2);
		}
	}

	void GameField::SwapColumnsGlobal()
	{
		Transpose();
		SwapRowsGlobal();
		Transpose();
	}

	void GameField::SwapCells(int i1, int j1, int i2, int j2)
	{
		if (i1 < 0 || j1 < 0 || i2 < 0 || j2 < 0 ||
			i1 >= Size() || j1 >= Size() || i2 >= Size() || j2 >= Size())
		{
			throw std::exception("argument out of range");
		}
		auto temp = _field[i1][j1];
		_field[i1][j1] = _field[i2][j2];
		_field[i2][j2] = temp;
	}

	void GameField::SwapLines(int line1, int line2)
	{
		if (line1 < 0 || line2 < 0 || line1 >= Size() || line2 >= Size())
		{
			throw std::exception("argument out of range");
		}
		for (int j = 0; j < Size(); j++)
		{
			SwapCells(line1, j, line2, j);
		}
	}

	void GameField::Reset()
	{
		for (int i = 0; i < Size(); i++)
		{
			for (int j = 0; j < Size(); j++)
			{
				_deleted[i][j] = false;
				_field[i][j] = true;
			}
		}
		Initialize();
	}

	int GameField::Size()
	{
		return _n * 3;
	}
}
