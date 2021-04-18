# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).
tests = [ {'description': 'PINA: 0x04, 0x00, 0x02  => PORTB: 0x01, state: pressA1' ,
    'steps': [ {'inputs': [('PINA', 0x04)], 'iterations':  1},
		 {'inputs': [('PINA', 0x00)], 'iterations':  1},
		 {'inputs': [('PINA', 0x02)], 'iterations':  1}],
    'expected': [('PORTB', 0x01)],
    },
    {'description': 'PINA: 0x04, 0x02 => PORTB: 0x08, state: pressA1',
    'steps': [ {'inputs': [('PINA', 0x04)],'iterations': 1}],
    'expected': [('PORTB', 0x00)],
    },
    {'description': 'PINA: 0x07 => PORTB: 0x00, state: pressA1',
    'steps': [ {'inputs': [('PINA', 0x07)],'iterations': 1} ],
    'expected': [('PORTB', 0x00)],
    },
    {'description': 'PINA: 0x04, 0x00, 0x02, 0x00  => PORTB: 0x01, state: pressA1' ,
    'steps': [ {'inputs': [('PINA', 0x04)], 'iterations':  1},
                 {'inputs': [('PINA', 0x00)], 'iterations':  1},
                 {'inputs': [('PINA', 0x02)], 'iterations':  1},
		{'inputs': [('PINA', 0x00)], 'iterations':  1}],
    'expected': [('PORTB', 0x01)],
    },
    {'description': 'PINA: 0x04, 0x00, 0x02, 0x00  => PORTB: 0x01, state: pressA1' ,
    'steps': [ {'inputs': [('PINA', 0x04)], 'iterations':  2},
                 {'inputs': [('PINA', 0x00)], 'iterations':  2},
                 {'inputs': [('PINA', 0x02)], 'iterations':  2},
                {'inputs': [('PINA', 0x00)], 'iterations':  2}],
    'expected': [('PORTB', 0x01)],
    },
    {'description': 'PINA: 0x04, 0x04, 0x02, 0x02  => PORTB: 0x01, state: pressA1' ,
    'steps': [ {'inputs': [('PINA', 0x04)], 'iterations':  1},
                 {'inputs': [('PINA', 0x04)], 'iterations':  1},
                 {'inputs': [('PINA', 0x02)], 'iterations':  1},
                {'inputs': [('PINA', 0x02)], 'iterations':  1}],
    'expected': [('PORTB', 0x01)],
    },
    {'description': 'PINA: 0x00 => PORTB: 0x00, state: pressA1',
    'steps': [ {'inputs': [('PINA', 0x00)],'iterations': 1} ],
    'expected': [('PORTB', 0x00)],
    },

    ]

# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
watch = ['hold1', 'hold2', 'reset']

