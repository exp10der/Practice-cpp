#include <string>
#include <iostream>
#include <memory>

class handler
{
public:
	virtual void set_successor(const std::shared_ptr<handler>& handler) { this->handler_ = handler; }

	virtual void handle_request(const int condition)
	{
		if (handler_ != nullptr)
			handler_->handle_request(condition);
	}

	virtual ~handler() = default;
private:
	std::shared_ptr<handler> handler_ = nullptr;
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
	std::shared_ptr<handler> handler1 = std::make_shared<concrete_handler1>(concrete_handler1{});
	std::shared_ptr<handler> handler2 = std::make_shared<concrete_handler2>(concrete_handler2{});

	handler1->set_successor(handler2);
	handler1->handle_request(2);


	return 0;
}
