# Philosophers
Issues related to thedining philosophers problem.
> Five philosophers dine together at the same table. Each philosopher has their own plate at the table. There is a fork between each plate. The dish served is a kind of spaghetti which has to be eaten with two forks. Each philosopher can only alternately think and eat. Moreover, a philosopher can only eat their spaghetti when they have both a left and right fork. Thus two forks will only be available when their two nearest neighbors are thinking, not eating. After an individual philosopher finishes eating, they will put down both forks. The problem is how to design a regimen (a concurrent algorithm) such that no philosopher will starve; i.e., each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think (an issue of incomplete information).  
> [Wikipedia-Dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

The conditions are as follows.
- Each philosopher must have a thread.
- The forks that philosophers have with each other must be locked by mutex to prevent overlap.

To prevent deadlock, the idea used is that each philosopher must always get from the right-hand fork, and the odd-numbered philosopher will try to get the fork a little later.

## Usage

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_time_each_philosophers_must_eat(option)]
```


Click here to see the visualizer used to check the execution results.
- [Philosophers visualizer](https://nafuka11.github.io/philosophers-visualizer/)
  

## Testing
### Third-party tester
I tested the library with this third-party tester:

- [MichelleJiam/LazyPhilosophersTester](https://github.com/MichelleJiam/LazyPhilosophersTester)

### Visualizer

- [nafuka11/Philosophers visualizer](https://nafuka11.github.io/philosophers-visualizer/)
