#ifndef ORDER_HPP_
#define ORDER_HPP_

class Order {
public:
  Order() = default;
  virtual ~Order() = default;
  virtual void Show() const = 0;
};

#endif /* end of include guard: ORDER_HPP_ */
