def run
  op = FileOperation.new
  op.copy_merge_dirs_replace_files
end

def verify_source
  assert_source_file('file1.txt', /source/)
  assert_source_nonexist('file2.txt')      
  assert_source_file('dir1/file1.txt', /source/)
  assert_source_nonexist('dir1/file2.txt')
end

def verify_target
  assert_target_file('file1.txt', /source/)
  assert_target_file('file2.txt', /target/)
  assert_target_file('dir1/file1.txt', /source/)
  assert_target_file('dir1/file2.txt', /target/)
end
