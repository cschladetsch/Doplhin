def longest_odd_subarray(nums):
  max_length = 0
  current_length = 0
  current_sum = 0

  for num in nums:
    current_sum += num

    if current_sum % 2 == 1:
      current_length += 1
      max_length = max(max_length, current_length)
    else:
      current_length = 0

  return max_length


if __name__ == '__main__':
    f=int(input("String of numbers: "))
    l=[]
    for x in range(f):
        string_numbers = int(input(f'Enter {x+1} string of numbers: '))
    l.append(string_numbers)
    longest_odd_subarray(f)
