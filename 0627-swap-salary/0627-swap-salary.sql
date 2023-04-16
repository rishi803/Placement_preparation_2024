# IF (sex = 'm', 'f', 'm')
# This will check whether sex is 'm':
# If yes then it will set SEX as 'f'
# else it will set it as 'm' [meaning when SEX = 'f']

# update Salary 
# set sex=IF (sex = 'm', 'f', 'm')


# REPLACE(string, old_string, new_string)
# string = 'fm' # row01 = 'f'. So, sex = 'f'. We'll now find 'f' in 'fm' and will replace it with ''. So, the result is 'm'.
# row02 = 'm'. So, sex = 'm'. We'll now find 'm' in 'fm' and will replace it with ''. So, the result is 'f'.

UPDATE salary 
SET sex = REPLACE ('ffm', sex, '');


