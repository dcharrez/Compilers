import numpy as np

fileName = "input.txt"

states = []
n_states =0

acceptingStates = []
n_accepting_states = 0

inputs = []
n_inputs = 0

transitions = []
n_transitions = 0

def displayData():
	print("States: ", states)
	print("Accepting States: ", acceptingStates)
	print("Inputs: ", inputs)
	print("Transitions", transitions)

def initializeTable():
	print("Generating Transitions Table .... ")
	table = np.full((n_states, n_states), -9)
	print(table)
	for i in transitions:
		table[int(i[0])-1][int(i[2])-1] = int(i[1])

	print("Table Filled with transitions .... ")
	print(table)

def main():
	global states, acceptingStates, inputs, n_states, \
						n_accepting_states, n_transitions, n_inputs
	with open(fileName, 'r') as f:
		while(True):
			line = f.readline().strip()
			if line == "states":
				n_states = int(f.readline())
				states = (f.readline().strip().split())
			elif line == "accepting states":
				n_accepting_states = int(f.readline())
				acceptingStates = (f.readline().strip().split())
			elif line == "inputs":
				n_inputs = int(f.readline())
				inputs = (f.readline().strip().split())
			elif line == "transitions":
				n_transitions = int(f.readline())
				for i in range( n_transitions ):
					tmp = (f.readline().strip().split())
					transitions.append( tmp )
				break
	f.close()
	print("File readed correctly... ")


if __name__ == '__main__':
	main()
	displayData()
	initializeTable()