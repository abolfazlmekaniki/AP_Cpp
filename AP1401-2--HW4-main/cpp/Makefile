CXX = g++
CXXFLAGS = -std=c++20 -Wall -c
LXXFLAGS = -std=c++20
OBJECTS = main.o account.o transaction.o savingsAccount.o checkingaccount.o creditAccount.o currency.o customer.o banking.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET) -lgtest -lgtest_main -pthread
main.o: src/main.cpp include/.
	$(CXX) $(CXXFLAGS) src/main.cpp
account.o:src/account.cpp
	$(CXX) $(CXXFLAGS) src/account.cpp
transaction.o:src/transaction.cpp 
	$(CXX) $(CXXFLAGS) src/transaction.cpp
savingsAccount.o:src/savingsAccount.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/savingsAccount.cpp
checkingaccount.o:src/checkingaccount.cpp include/account.h
	$(CXX) $(CXXFLAGS) src/checkingaccount.cpp
creditAccount.o:src/creditAccount.cpp include/account.h 
	$(CXX) $(CXXFLAGS) src/creditAccount.cpp
currency.o:src/currency.cpp 
	$(CXX) $(CXXFLAGS) src/currency.cpp
customer.o:src/customer.cpp 
	$(CXX) $(CXXFLAGS) src/customer.cpp
banking.o:src/banckingSystem.cpp 
	$(CXX) $(CXXFLAGS) src/banckingSystem.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)