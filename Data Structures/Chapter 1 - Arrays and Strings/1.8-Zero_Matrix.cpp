#include <iostream>
#include <vector>

void nullify_row(std::vector<std::vector<int> >& my_vector, const int row_nullified)
{
    for(int i = 0; i < my_vector.at(0).size(); i++)
    {
        my_vector[row_nullified][i] = 0;
    }
}

void nullify_cols(std::vector<std::vector<int> >& my_vector, const int col_nullified)
{
    for(int i = 0; i < my_vector.size(); i++)
    {
        my_vector[i][col_nullified] = 0;
    }
}

// Assume in-place transformation
void zeroMatrix(std::vector<std::vector<int> >& my_vector)
{
    std::vector<bool> rows_zero(my_vector.size(), false);
    std::vector<bool> cols_zero(my_vector.at(0).size(), false);

    for(int i = 0; i < rows_zero.size(); i++)
    {
        for(int j = 0; j < cols_zero.size(); j++)
        {
            if(my_vector.at(i).at(j) == false)
            {
                rows_zero[i] = true;
                cols_zero[j] = true;
            }
        }
    }

    // Nullify rows
    for(int i = 0; i < rows_zero.size(); i++)
    {
        if(rows_zero[i]) nullify_row(my_vector, i);
    }

    // Nullify columns
    for(int i = 0; i < cols_zero.size(); i++)
    {
        if(cols_zero[i]) nullify_cols(my_vector, i);
    }
}

int main()
{
    std::vector<std::vector<int> > vector1(3, std::vector<int>(4,0));

    std::cout << "Before zero matrix:" << std::endl;

    for(int i = 0; i < vector1.size(); i++)
    {
        for(int j = 0; j < vector1[i].size(); j++)
        {
            vector1[i][j] = rand() % 5;
            printf("%d, ", vector1[i][j]);
        }
        printf("\n");
    }

    std::cout << std::endl << std::endl << "After zero matrix:" << std::endl;
    zeroMatrix(vector1);

    for(int i = 0; i < vector1.size(); i++)
    {   
        for(int j = 0; j < vector1[i].size(); j++)
        {
            printf("%d, ", vector1[i][j]);
        }
        printf("\n");
    }
}