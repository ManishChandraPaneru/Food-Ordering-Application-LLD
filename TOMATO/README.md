# TOMATO Food Delivery System

A complete C++ food delivery application demonstrating multiple design patterns and object-oriented programming concepts.

## Features

- **User Management**: User registration and management
- **Restaurant Management**: Multiple restaurants with menus
- **Cart System**: Add/remove items, calculate totals
- **Order Processing**: Delivery and Pickup orders
- **Payment Integration**: Multiple payment strategies (UPI, Credit Card)
- **Notifications**: Order confirmation notifications
- **Time Management**: Order scheduling and timestamps

## Design Patterns Used

1. **Singleton Pattern**: RestaurantManager, OrderManager
2. **Strategy Pattern**: Payment strategies (UPI, Card)
3. **Factory Pattern**: Order creation (Now vs Scheduled orders)
4. **Observer Pattern**: Notification service
5. **Template Method**: Order processing workflow

## Project Structure

```
TOMATO/
├── main.cpp                      # Entry point
├── app.h                         # Main application logic
├── models/                       # Data models
│   ├── User.h                   # User entity
│   ├── Restaurant.h             # Restaurant entity
│   ├── MenuItem.h               # Menu item entity
│   ├── Cart.h                   # Shopping cart
│   ├── Order.h                  # Base order class
│   ├── DeliveryOrder.h          # Delivery order implementation
│   └── PickupOrder.h            # Pickup order implementation
├── managers/                     # Business logic managers
│   ├── RestaurantManager.h      # Restaurant management
│   └── OrderManager.h           # Order management
├── strategies/                   # Payment strategies
│   ├── PaymentStrategies.h      # Base payment interface
│   ├── UPIStrategy.h           # UPI payment
│   └── CardPaymentstrategy.h    # Card payment
├── factories/                    # Order factories
│   ├── OrderFactory.h           # Base factory
│   ├── NowOrderFactory.h        # Immediate orders
│   └── ScheduledOrderFactory.h  # Scheduled orders
├── services/                     # Additional services
│   └── NotificationService.h    # Order notifications
└── utils/                        # Utility classes
    └── TimeUtils.h              # Time management
```

## How to Compile and Run

```bash
cd TOMATO
g++ -I. -o tomato main.cpp
./tomato
```

## Sample Output

The application demonstrates:
1. User creation and restaurant selection
2. Menu browsing and item selection
3. Cart management
4. Order placement with different payment methods
5. Both delivery and pickup order types
6. Real-time notifications

## Key OOP Concepts Demonstrated

- **Encapsulation**: Private data members with public interfaces
- **Inheritance**: Order hierarchy (DeliveryOrder, PickupOrder)
- **Polymorphism**: Payment strategies, order types
- **Abstraction**: Abstract base classes for extensibility
- **Composition**: User has Cart, Order has User and Restaurant

## Design Principles Applied

- **Single Responsibility Principle**: Each class has one clear purpose
- **Open/Closed Principle**: Easy to extend with new payment methods or order types
- **Liskov Substitution Principle**: Derived classes can substitute base classes
- **Interface Segregation**: Focused interfaces for specific functionality
- **Dependency Inversion**: Depend on abstractions, not concrete implementations

## Educational Value

This project is perfect for learning:
- Design pattern implementation
- Object-oriented programming in C++
- Memory management
- Code organization and structure
- Real-world application design

## Future Enhancements

- Database integration
- User authentication
- Order tracking system
- Rating and review system
- Delivery personnel management
- Real-time order updates
