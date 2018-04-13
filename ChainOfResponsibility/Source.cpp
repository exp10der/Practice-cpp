#include <string>
#include <iostream>

class handler
{
public:
	virtual void set_successor(handler* handler) { this->handler_ = handler; }

	virtual void handle_request(const int condition)
	{
		if (handler_ != nullptr)
			handler_->handle_request(condition);
	}

	virtual ~handler() = default;
private:
	handler * handler_ = nullptr;
};

class concrete_handler1 : public handler
{
public:
	void handle_request(const int condition) override
	{
		if (condition == 1)
			std::cout << "Request processed: 'ConcreteHandler1'." << std::endl;
		else
			handler::handle_request(condition);
	}
};

class concrete_handler2 : public handler
{
public:
	void handle_request(const int condition) override
	{
		if (condition == 2)
			std::cout << "Request processed: 'ConcreteHandler2'." << std::endl;
		else
			handler::handle_request(condition);
	}
};


int main()
{
	handler* h1 = new concrete_handler1{};
	handler* h2 = new concrete_handler2{};
	h1->set_successor(h2);
	h1->handle_request(2);

	delete h1;
	delete h2;

	return 0;
}
