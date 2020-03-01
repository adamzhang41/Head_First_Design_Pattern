#include <string>
#include <vector>
#include <iostream>
#include <memory>

using std::shared_ptr;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Pizza{
    protected:
    std::string name;
    std::string dough;
    std::string sauce;
    std::vector<std::string> toppings;
    public:
    void addtopping(std::string item)
    {
        toppings.push_back(item);
    }
    void prepare()
    {
        std::cout << "Preparing" << name << std::endl;
        std::cout << "Tossing dough..." << std::endl;
        std::cout << "Adding sauce..." << std::endl;
        std::cout << "Adding toppings: " << std::endl;
        for(auto it = toppings.cbegin(); it != toppings.cend(); it++)
            std::cout << *it << std::endl;
    }
    virtual void bake()
    {
        std::cout << "Bake for 25min at 350" << std::endl;
    }
    virtual void cut()
    {
        std::cout << "Cutting the pizza into diagonal slices" << std::endl;
    }
    virtual void box()
    {
        std::cout << "Place pizza in official pizzastore box" << std::endl;
    }
    std::string getName()
    {
        return name;
    }
    virtual ~Pizza() = default;
};

class NYStyleCheesePizza : public Pizza{
public:
    NYStyleCheesePizza(){
        name = "NY Style Sauce and Cheese Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
        addtopping("Grated Reggiano Cheese");
    }
};
class ChicagoStyleCheesePizza : public Pizza{
public:
    ChicagoStyleCheesePizza(){
        name = "Chicago Style Deep Dish Cheese Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        addtopping("Shredded Mozzarella Cheese");
    }
    void cut(){
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};

class CheesePizza : public Pizza{
public:
    CheesePizza(){
        name = "Cheese Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        addtopping("Shredded Mozzarella Cheese");
    }
    void cut(){
        std::cout << "Cutting the pizza into square slices" << std::endl;
    }
};
class PepperoniPizza : public Pizza{
public:
    PepperoniPizza(){
        name = "Pepperoni Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
        addtopping("Grated Reggiano Cheese");
    }
};


class SimplePizzaFactory{
    public:
    shared_ptr<Pizza> creatPizza(std::string type)
    {
        if(type == "cheese")
        {
            return (shared_ptr<Pizza>)(new CheesePizza());
        }else if(type == "pepperoni")
        {
            return (shared_ptr<Pizza>)(new PepperoniPizza());
        }else
        {
            return nullptr;
        }
    }
};

class PizzaStore{
SimplePizzaFactory factory;
public:
    PizzaStore(SimplePizzaFactory factory)
    {
        this->factory = factory;
    }
    shared_ptr<Pizza> orderPizza(std::string type){
        shared_ptr<Pizza> pizza(factory.creatPizza(type));

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }
};
