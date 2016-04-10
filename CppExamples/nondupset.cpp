#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>

template<typename T, typename Hash> class HashPointer
{
public:
    size_t operator() (const T* value) const
    {
        return m_hash(*value);
    }

private:
    Hash m_hash;
};

template<typename T, typename Equal> class EqualPointer
{
public:
    bool operator () (const T* first, const T* second) const
    {
        return m_equal(*first, *second);
    }

private:
    Equal m_equal;
};

template<typename T, typename Hash = std::hash<T>, typename Equal = std::equal_to<T>>
void RemoveDuplicates(std::vector<T>& entries)
{
    std::unordered_set<T*, HashPointer<T, Hash>, EqualPointer<T, Equal> > uniques;
    for (size_t index = 0; index < entries.size(); )
    {
        T* ptr = &entries[index];
        auto status = uniques.insert(ptr);
        if (status.second)
        {
            ++index;
        }
        else
        {
            std::swap(*ptr, entries.back());
            entries.pop_back();
        }
    }
}

int nondupset()
{
    std::vector<int> V;
    for (int i = 0; i < 200; ++i)
        V.push_back(i);

    std::vector<int> otherV = V;
    for (auto i : V)
        otherV.push_back(i);

    for (int i = 700; i < 715; ++i)
        otherV.push_back(i);

    sort(otherV.begin(), otherV.end());
    for (auto i : otherV)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "otherV.size() with duplicates: " << otherV.size() << "\n";
    std::cout << "otherV.capacity with duplicates: " << otherV.capacity() << "\n";
    for (auto i : otherV)
        std::cout << i << " ";
    std::cout << std::endl;

    RemoveDuplicates(otherV);

    std::cout << "Size without duplicates: " << otherV.size();
    for (auto i : otherV)
        std::cout << i << " ";
    std::cout << std::endl;

    sort(otherV.begin(), otherV.end());
    for (auto i : otherV)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}