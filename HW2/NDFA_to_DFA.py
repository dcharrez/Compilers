import numpy as np

in_fileName = "input.txt"
out_fileName = "output.txt"


class NFA:
	def __init__(self):
		self.numStates = 0
		self.states = []
		self.numSymbols = 0
		self.symbols = []
		self.numAcceptingStates = 0
		self.acceptingStates = []
		self.start_state = 0
		self.numTransitions = 0
		self.transitions = []

	def nfa_from_file(self, fileName):
		with open(in_fileName, 'r') as f:
			while(True):
				line = f.readline().strip()
				if line == "states":
					self.numStates = int(f.readline())
					self.states = (f.readline().strip().split())
				elif line == "accepting states":
					self.numAcceptingStates = int(f.readline())
					self.acceptingStates = (f.readline().strip().split())
				elif line == "inputs":
					self.numSymbols = int(f.readline())
					self.symbols = (f.readline().strip().split())
				elif line == "transitions":
					self.numTransitions = int(f.readline())
					for i in range(self.numTransitions):
						transition_func_line = f.readline().strip().split()

						starting_state = int(transition_func_line[0])
						transition_symbol = transition_func_line[1]
						ending_state = int(transition_func_line[2])
		
						transition_function = (starting_state, \
							transition_symbol, ending_state)
						self.transitions.append( transition_function )
					break
		f.close()
		print("File read correctly... ")

	def print_nfa(self):
		print("Number of States: ", self.numStates)
		print("States: ", self.states)
		print("Number of symbols: ", self.numSymbols)
		print("Symbols: ", self.symbols)
		print("Number of Accepting States: ", self.numAcceptingStates)
		print("Accepting States: ", self.acceptingStates)
		print("Start State: ", self.start_state)
		print("Number of Transitions: ", self.numTransitions)
		print("Transitions: ", self.transitions)

	
if __name__ == '__main__':
	nfa = NFA()
	nfa.nfa_from_file(in_fileName)
	nfa.print_nfa()