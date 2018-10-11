# 2^16 possible addresses,
# which are mapped onto 8*1024 bytes
bc -l <<< '2^16/(8*1024)'
