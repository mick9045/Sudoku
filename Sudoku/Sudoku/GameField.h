#pragma once
 

namespace Sudoku
{
	class GameField
	{
	public:
		GameField(int complexity = 4);
		~GameField();
		int Get(int x, int y);
		int Set(int x, int y, int value);
		bool IsDeleted(int x, int y);
		bool IsSolved();
		void Reset();
	protected:
		void Initialize();

		void GenerateField();
		void RemoveRandomCells();
		void Transpose();
		void SwapRowsBlock();
		void SwapColumnsBlock();
		void SwapRowsGlobal();
		void SwapColumnsGlobal();
		void SwapCells(int i1, int j1, int i2, int j2);
		void SwapLines(int line1, int line2);
		int Size();
	private:
		const int _n = 3;
		int _complexity;
		int _field[9][9];
		bool _deleted[9][9];
	};
}

