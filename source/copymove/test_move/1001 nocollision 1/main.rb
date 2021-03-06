def run
  op = FileOperation.new
  op.move_replace_all
end

def verify_source
  assert_source_nonexist('file1.txt')
end

def verify_target
  assert_target_file('file1.txt', /source/)
  assert_target_file('ignore.txt', /target/)
end

