#include <iostream>
#include "TMatrix.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	/*	int  size1 = 0,
			size2 = 0,
			size3 = 0;


		cout << "Введите размерность для V1: ";
		cin >> size1;

		TVector<int> V1(size1);
		cin >> V1;
		cout << "V1 = " << V1;

		cout << "Введите размерность для  V2: ";
		cin >> size2;

		TVector<int> V2(size2);
		cin >> V2;
		cout << "V2 = " << V2;


		cout << "Введите размерность для V3: ";
		cin >> size3;

		TVector<int> V3(size3);
		cin >> V3;
		cout << "V3 = " << V3;


		//	cout << "размер V2 = " << V2.GetSize() << endl;

			//cout << "стартовый индекс V2 = " << V2.GetStartIndex() << endl;

		int pos;
		do {
			cout << "Введите позицию для V3: " << endl;
			cin >> pos;
		} while (pos > size3);
		cout << "Элемент на позиции " << pos << "= " << V3.GetValue(pos - 1) << endl;



		int num;
		cout << "Введите число для вставки: ";
		cin >> num;

		int pos1 = pos - 1;
		V3.SetValue(pos1, num);
		cout << "Новое V3 =" << V3 << endl;

		cout << "V2 равен V1 ?" << endl;
		if (V2 == V1)
			cout << "равен" << endl;
		else cout << "не равен" << endl;


		cout << "V3 = V2: " << endl;
		V3 = V2;
		cout << V3 << endl;

		int con;
		cout << "Введите константу: ";
		cin >> con;

		TVector<int> V4(size3);
		V4 = V3 + con;
		cout << "V3 + " << con << " = " << V4 << endl;

		V4 = V3 - con;
		cout << " V3 - " << con << " = " << V4 << endl;


		V4 = V3 * con;
		cout << "V3 * " << con << " = " << V4 << endl;

		int length = V3.Length();
		cout << "Длина V3 ~ " << length << endl;


		cout << "V3 = V1 + V2" << endl;
		if (V1.GetSize() == V2.GetSize()) {
			V3 = V1 + V2;
			cout << "V3 = " << V3;
			cout << endl;
		}
		else {
			cout << "Неверные размерности" << endl;
		}

		cout << "V3 = V1 - V2" << endl;
		if (V1.GetSize() == V2.GetSize()) {
			V3 = V1 - V2;
			cout << "V3 = " << V3;
			cout << endl;
		}
		else {
			cout << "Неверные размерности" << endl;
		}
		con = 0;
		cout << "C = (V1,V2)" << endl;
		if (size1 == size2)
		{
			con = V1 * V2;
			cout << "(V1,V2) = " << con;
		}
		else cout << "размерности V1 и V2 не совпадают";
		cout << endl;
		//system("pause");
		//return 0;
		*/
		//cout << "Матрицы" << endl;

	int sizee1 = 0,
		sizee2 = 0,
		sizee3 = 0;

	cout << "Введите количество строк(столбцов) в A: ";
	cin >> sizee1;
	TMatrix<int> A(sizee1);
	cin >>A ;
	cout << A;
	//cout << endl << "A = " << A << endl;

	cout << "Введите количество строк(столбцов) в B: ";
	cin >> sizee2;

	TMatrix<int> B(sizee2);
	//cout << endl << "B = " << endl;
	cin >> B;
	cout << B;

	cout << "Введите количество строк(столбцов) в C: ";
	cin >> sizee3;

	TMatrix<int> C(sizee3);
	cin >> C;
	cout << C;


	TMatrix<int> C1(sizee3);
	C1 = C;
	cout << "C1 = C = ";
	cout << C1;


	cout << endl << "B равен C ?" << endl;
	if (B == C) {
		cout << "равен" << endl;
	}
	else
		cout << "не равен" << endl;

	TMatrix<int> C3(sizee3);
	cout << "C + A= " << endl;
	C3 = C + A;
	cout << C3;

	TMatrix<int> C4(sizee3);
	cout << "C * A: " << endl;
	C4 = C * A;
	cout << C4;

	TMatrix<int> C5(sizee3);
	cout << endl << "C - A: " << endl;
	C = C - A;
	cout << C5;


	system("pause");
	return 0;
}






#pragma once

#ifndef _TMATRIX_H
#define _TMATRIX_H

#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;


template <class Elem>
class TVector {
protected:
	Elem  *pVector;
	int Size;
	int startIndex;

public:
	TVector(int _size = 3, int _startIndex = 0);//констр инициализации
	TVector(const TVector &op2);//конст копирования
	~TVector();//деструктор 
	int GetSize() const;//получаем размер
	int GetStartIndex() const;//получаем старт. индекс
	int Length();//получаем длину векторп
	Elem& GetValue(int pos1);
	void SetValue(int pos1, Elem &num);
	Elem& operator[](int pos1);
	bool operator==(const TVector &op2) const;
	TVector& operator=(const TVector &op2);
	TVector operator+(const Elem &con);
	TVector operator-(const Elem &con);
	TVector operator*(const Elem &con);
	TVector operator+(const TVector &op2);
	TVector operator-(const TVector &op2);
	Elem operator*(const TVector &op2);

	friend istream& operator>>(istream &cin, TVector& op2) {
		cout << "Введите Вектор: " << endl;

		for (int i = 0; i < op2.Size; i++) {
			cin >> op2.pVector[i];
		}

		cout << endl;
		return cin;
	}

	friend ostream& operator<<(ostream &cout, const TVector& op2) {


		cout << "( ";
		for (int i = 0; i < op2.Size; i++) {
			cout << op2.pVector[i] << ' ';
		}

		cout << ")" << endl;
		return cout;
	}
};

#endif

//констр инициализации
template <class Elem>
TVector<Elem>::TVector(int _size, int _startIndex) : Size(_size), startIndex(_startIndex) {
	pVector = new Elem[Size];
}

//конст копирования
template <class Elem>
TVector<Elem>::TVector(const TVector<Elem> &op2) : Size(op2.Size), startIndex(op2.startIndex) {
	pVector = new Elem[Size];

	for (int i = 0; i < Size; i++) {
		pVector[i] = op2.pVector[i];
	}
}

//деструктор
template <class Elem>
TVector<Elem>::~TVector() {
	delete[] pVector;
	pVector = NULL;
}


//получаем размер
template <class Elem>
int TVector<Elem>::GetSize() const {
	return Size;
}

//получаем стартовый индекс
template <class Elem>
int TVector<Elem>::GetStartIndex() const {
	return startIndex;
}

//получаем длину вектора
template <class Elem>
int TVector<Elem>::Length() {
	int length = 0;
	for (int i = 0; i < Size; i++) {
		length += pVector[i] * pVector[i];
	}

	return sqrt(length);
}

template <class Elem>
Elem& TVector<Elem>::GetValue(int pos1) {
	assert((pos1 - startIndex) >= 0 && (pos1 - startIndex) < Size);
	return pVector[pos1 - startIndex];
}

template <class Elem>
void TVector<Elem>::SetValue(int pos1, Elem &num) {
	pVector[pos1] = num;
}





template <class Elem>
bool TVector<Elem>::operator==(const TVector<Elem> &op2) const {
	int a=0;
	if ((Size != op2.Size) || (startIndex != op2.startIndex))
		return false;

	for (int i = 0; i < Size; i++) {
		if (pVector[i] == op2.pVector[i])
			true;
		else
			return false;
	}

	return true;
}

template <class Elem>
TVector<Elem>& TVector<Elem>::operator=(const TVector<Elem> &op2) {
	if (this != &op2) {
		if (Size != op2.Size) {
			delete[] pVector;

			Size = op2.Size;
			startIndex = op2.startIndex;

			pVector = new Elem[Size];
		}
	}

	if (pVector != NULL) {
		for (int i = 0; i < Size; i++) {
			pVector[i] = op2.pVector[i];
		}
	}

	return *this;
}


template <class Elem>
TVector<Elem> TVector<Elem>::operator+(const Elem &con) {
	TVector res(Size, startIndex);
	for (int i = 0; i < Size; i++) {
		res.pVector[i] = pVector[i] + con;
	}

	return res;
}

template <class Elem>
TVector<Elem> TVector<Elem>::operator-(const Elem &con) {
	TVector res(Size, startIndex);
	for (int i = 0; i < Size; i++) {
		res.pVector[i] = pVector[i] - con;
	}

	return res;
}

template <class Elem>
TVector<Elem> TVector<Elem>::operator*(const Elem &con) {
	TVector res(Size, startIndex);
	for (int i = 0; i < Size; i++) {
		res.pVector[i] = pVector[i] * con;
	}

	return res;
}





template <class Elem>
TVector<Elem> TVector<Elem>::operator+(const TVector<Elem> &op2) {
	TVector res(Size, startIndex);
	for (int i = 0; i < Size; i++) {
		res.pVector[i] = pVector[i] + op2.pVector[i];
	}

	return res;
}

template <class Elem>
TVector<Elem> TVector<Elem>::operator-(const TVector<Elem> &op2) {
	TVector res(Size, startIndex);
	for (int i = 0; i < Size; i++) {
		res.pVector[i] = pVector[i] - op2.pVector[i];
	}

	return res;
}

template <class Elem>
Elem TVector<Elem>::operator*(const TVector<Elem> &op2) {
	int res = 0;

	for (int i = 0; i < Size; i++) {
		res += pVector[i] * op2.pVector[i];
	}

	return res;
}



template <class Elem>
Elem& TVector<Elem>::operator[](int pos1) {
	assert((pos1 - startIndex) >= 0 && (pos1 - startIndex) < Size);
	return pVector[pos1 - startIndex];
}

template <class Elem>

class TMatrix : public TVector<TVector<Elem>> {
public:
	TMatrix(int rows = 10);
	TMatrix(const TMatrix &op2);
	TMatrix(const TVector<TVector<Elem>> &matr);

	//TMatrix Transpose();

	bool operator==(const TMatrix &op2) const;
	TMatrix& operator=(const TMatrix &op2);
	TMatrix operator+(const TMatrix &op2);
	TMatrix operator-(const TMatrix &op2);
	TMatrix operator*(const TMatrix &op2);

	friend istream& operator>>(istream &cin, TMatrix&op2) {
		for (int i = 0; i < op2.Size; i++) {
			cout << "Введите  " << i + 1 << " строку поэлементно: ";
			cin >> op2.pVector[i];
		}

		cout << endl;
		return cin;
	}

	friend ostream& operator<<(ostream &cout, const TMatrix& op2) {
		cout << "Ваша матрица: " << endl;

		for (int i = 0; i < op2.Size; i++) {
			cout << op2.pVector[i] ;
		}

		return cout;
	}
};

template <class Elem>
TMatrix<Elem>::TMatrix(int rows) : TVector<TVector<Elem>>::TVector(rows) {
	for (int i = 0; i < rows; i++) {
		TMatrix::pVector[i] = TVector<Elem>(rows - i, i);
	}
}
//Конструктор копирования
template <class Elem>
TMatrix<Elem>::TMatrix(const TMatrix<Elem> &op2) : TVector<TVector<Elem>>(op2) {}

//Конструктор преобразования типа 
template <class Elem>
TMatrix<Elem>::TMatrix(const TVector<TVector<Elem>> &matr) : TVector<TVector<Elem>>(matr) {}



template <class Elem>
TMatrix<Elem>& TMatrix<Elem>::operator=(const TMatrix<Elem> &op2) 
{
	if (this != &op2)
	{
		if (TMatrix::Size != op2.Size)
		{
			delete[] TMatrix::pVector;
			TMatrix::pVector = new TVector<Elem>[TMatrix::Size];
		}
		TMatrix::Size = op2.Size;
		TMatrix::startIndex = op2.startIndex;
	}

		for (int i = 0; i < TMatrix::Size; i++) {
			TMatrix::pVector[i] = op2.pVector[i];
		}
	
	return *this;
}
template <class Elem>
bool TMatrix<Elem>::operator==(const TMatrix<Elem> &op2) const {

	return TVector<TVector<Elem>>::operator==(op2);
}

template <class Elem>
TMatrix<Elem> TMatrix<Elem>::operator+(const TMatrix<Elem> &op2) {
	return TVector<TVector<Elem>>::operator+(op2);
}

template <class Elem>
TMatrix<Elem> TMatrix<Elem>::operator-(const TMatrix<Elem> &op2) {
	return TVector<TVector<Elem>>::operator-(op2);
}

template <class Elem>
TMatrix<Elem> TMatrix<Elem>::operator*(const TMatrix<Elem> &op2) {

	TMatrix res(TMatrix::Size);

	for (int i = 0; i < TMatrix::Size; i++) {
		for (int j = 0; j < TMatrix::Size; j++) {
			res.pVector[i][j] = 0;
			for (int k = 0; k < j + 1; k++)
			{
				res.pVector[i][j] = res.pVector[i][j] + (TMatrix::pVector[i][k] *op2.pVector[k][j]);
			}
		}
	}

	return res;
}

