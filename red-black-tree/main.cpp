#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <chrono>
#include <random>

const int SIZE = 100000; // number of elements to test with

int main()
{
    std::set<int> rbt;
    std::vector<int> vec;
    std::unordered_set<int> hash;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, SIZE);
    int random_data[SIZE];

    // generate random data
    for (int i = 0; i < SIZE; i++)
        random_data[i] = distribution(generator);

    // [rbtree] Benchmark Insertion
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++)
        rbt.insert(random_data[i]);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "[rbtree]Time taken for " << SIZE << " insertions: " << duration.count() << " ms\n";

    // [rbtree] Benchmark Search
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++)
        rbt.find(random_data[i]);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "[rbtree]Time taken for " << SIZE << " searches: " << duration.count() << " ms\n";

    // [rbtree] size
    std::cout << "[rbtree]Size: " << rbt.size() << "\n";

    // [rbtree] Benchmark Deletion
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++)
        rbt.erase(random_data[i]);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "[rbtree]Time taken for " << SIZE << " deletions: " << duration.count() << " ms\n";

    // [hash] Benchmark Insertion
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++)
        hash.insert(random_data[i]);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "[hash]Time taken for " << SIZE << " insertions: " << duration.count() << " ms\n";

    // [hash] Benchmark Search
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++)
        hash.find(random_data[i]);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "[hash]Time taken for " << SIZE << " searches: " << duration.count() << " ms\n";

    // [hash] size
    std::cout << "[hash]Size: " << hash.size() << "\n";

    // [hash] Benchmark Deletion
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++)
        hash.erase(random_data[i]);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "[hash]Time taken for " << SIZE << " deletions: " << duration.count() << " ms\n";

    // [vec] Benchmark Insertion
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++)
        vec.push_back(random_data[i]);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "[vec]Time taken for " << SIZE << " insertions: " << duration.count() << " ms\n";

    // [vec] Benchmark Search
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++)
        std::find(vec.begin(), vec.end(), random_data[i]);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "[vec]Time taken for " << SIZE << " searches: " << duration.count() << " ms\n";

    // [vec] size
    std::cout << "[vec]Size: " << vec.size() << "\n";

    // [vec] Benchmark Deletion
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++)
        vec.erase(std::find(vec.begin(), vec.end(), random_data[i]));
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "[vec]Time taken for " << SIZE << " deletions: " << duration.count() << " ms\n";

    return 0;
}
