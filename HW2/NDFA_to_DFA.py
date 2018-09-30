import numpy as np

in_fileName = "input.txt"
out_fileName = "output.txt"

EPS = 'e'
START = 'x'
END = 'y'

class NFA:
	def __init__(self):
		self.numStates = 0
		self.states = []
		self.numSymbols = 0
		self.symbols = []
		self.numAcceptingStates = 0
		self.acceptingStates = []
		self.start_state = '0'
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

						if (transition_func_line[0]) == '0':
							starting_state = START
						else:
							starting_state = transition_func_line[0]
						if (transition_func_line[2]) == self.acceptingStates[0]:
							ending_state = END
						else:
							ending_state = transition_func_line[2]
						if (transition_func_line[1]) == '-1':
							transition_symbol = EPS
						else:
							transition_symbol = transition_func_line[1]
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

class DFA:
	def __init__(self):
		self.num_states = 0
		self.symbols = []
		self.num_accepting_states = 0
		self.accepting_states = []
		self.start_state = 0
		self.transitions = []
		self.q = []

	def eps_closure(self, nfa, node_set):
		if node_set == set([]):
			return node_set
		res = node_set.copy()
		for node in node_set:
			next_list = nfa.get(node)
			if next_list:
				for next in next_list:
					if next[1] == EPS:
						res.add(next[0])
						if next[0] != node:
							res |= self.eps_closure(nfa, set([next[0]]))
		return res

	def next_set(self, nfa, now_set, c):
		res = set([])
		for node in now_set:
			next_list = nfa.get(node)
			if next_list:
				for next in next_list:
					if next[1] == c:
						res.add(next[0])
		return res

	def convert_from_nfa(self, NFA):
		self.symbols = NFA.symbols
		self.start_state = NFA.start_state
		nfa = {}
		lit = set([])
		for transition in NFA.transitions:
			if nfa.get(transition[0]):
				nfa[transition[0]].append((transition[2], transition[1]))
			else:
				nfa[transition[0]] = [(transition[2], transition[1])]
			lit.add(transition[1])
		lit.remove(EPS)
		liter = list(lit)
		liter.sort()
		q = [self.eps_closure(nfa, set([START]))]
		status = [q[0]]
		dfa_str = ''
		dfa = {}
		end_node = []
		mid_node = []
		print( "NFA ", nfa )
		print( "Q ", q)
		while q:
			now = q.pop(0)
			i = status.index(now)
			now_index = '%d' % i
			end_str = ''
			if END in now:
				end_str = '*'
				end_node.append(i)
			else:
				mid_node.append(i)
			print("NOW: ", now, end=' ')
			dfa_str += now_index + end_str + ' '
			next_dict = {}
			for c in liter:
				next = self.eps_closure(nfa, self.next_set(nfa, now, c))
				if not next in status and next:
					q.append(next)
					status.append(next)
				j = status.index(next) if next else -1
				next_index = '%d' % j
				dfa_str += next_index + ' '
				next_dict[c] = j
			dfa_str += '\n'
			dfa[i] = next_dict
		print('\ns %s\n%s\n' % (' '.join(liter), dfa_str))

	
if __name__ == '__main__':
	nfa = NFA()
	dfa = DFA()
	nfa.nfa_from_file(in_fileName)
	nfa.print_nfa()
	dfa.convert_from_nfa(nfa)
	# dfa.print_dfa()