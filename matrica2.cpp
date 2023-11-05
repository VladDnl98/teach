#include <iostream>
#include <vector>
#include <thread>

void multiplyElements(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2, std::vector<std::vector<int>>& result, int i, int j) {
    int sum = 0;
    for (size_t k = 0; k < matrix1[0].size(); ++k) {
        sum += matrix1[i][k] * matrix2[k][j];
    }
    result[i][j] = sum;
}

std::vector<std::vector<int>> multiplyMatrix(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    size_t rows1 = matrix1.size();
    size_t cols1 = matrix1[0].size();
    size_t cols2 = matrix2[0].size();

    std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

    std::vector<std::thread> threads;

    for (size_t i = 0; i < rows1; ++i) {
        for (size_t j = 0; j < cols2; ++j) {
            threads.emplace_back(multiplyElements, std::ref(matrix1), std::ref(matrix2), std::ref(result), i, j);
        }
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<int>> matrix2 = {{7, 8}, {9, 10}, {11, 12}};

    std::vector<std::vector<int>> result = multiplyMatrix(matrix1, matrix2);

    for (const auto& row : result) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}