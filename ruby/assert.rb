def assert(val, msg = '', file = __FILE__, line = __LINE__)
  if !val
    exc = "#{file}:#{line}: asertion failed"
    exc += ": #{msg}" if msg.length > 0
    raise exc
  end
end
