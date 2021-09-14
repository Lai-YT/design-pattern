#ifndef ORDER_HPP_
#define ORDER_HPP_

// interface of component and decorator
class Order {
public:
  virtual ~Order() = default;
  virtual void Show() = 0;
};


#endif /* end of include guard: ORDER_HPP_ */
