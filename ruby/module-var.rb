module M

  def self.set_backtrace
    @@options[:backtrace] = true
  end

  def self.backtrace
    @@options[:backtrace]
  end

  private

  @@options = { backtrace: false }
end


puts "backtrace: #{M.backtrace}"

M.set_backtrace

puts "backtrace: #{M.backtrace}"
