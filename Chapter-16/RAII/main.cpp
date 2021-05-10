/* Example of the RAII concept. */

#include <iostream>

void printArray(const double* arry, const size_t size);

class RAII final
{
public:
        RAII(size_t size)
                : m_size {size}, m_resource { new double[m_size] }
        {}

        ~RAII()
        {
                std::cout << "Freeing memory..." << std::endl;
                delete[] m_resource;
        }

        size_t size() const { return m_size; }

        /* Delete the copy constructor and the copy assignment operator. */
        RAII(const RAII& src) = delete;
        RAII operator=(const RAII& src) = delete;

        /* Array subscript operator */
        double& operator[](size_t index) { return m_resource[index]; }
        const double& operator[](size_t index) const { return m_resource[index]; }

        double* get() const noexcept { return m_resource; }
        double* release() noexcept
        {
                double* result = m_resource;
                m_resource = nullptr;
                return result;
        }

private:
        size_t m_size;
        double* m_resource;
};

int
main()
{
        RAII raii { 10 };

        for (size_t i {}; i < raii.size(); ++i)
                raii[i] = i;

        printArray(raii.get(), raii.size());

        double* resource { raii.get() };

        printArray(resource, raii.size());

        /* This is a problem. I don't whether the authors knew about this
         * but, indeed, deleting the pointer got through the get() member function
         * causes an error when trying to delete the object's one.
         * You know, they both point to the same memory address... */
        delete[] resource;
}

void
printArray(const double* arr, const size_t size)
{
        size_t count {};
        const size_t numbers_per_line {10};
        for (size_t i {} ; i < size; ++i) {
                std::cout << arr[i] << ' ';
                if (!(++count) % numbers_per_line) std::cout << std::endl;
        }
        std::cout << std::endl;
}
