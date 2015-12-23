# coding: utf-8
class Release

  def initialize
    @h = {}
  end

  def sha256()
    @h.update h
  end

  def shasum(platform)
    @h[platform]
  end
end


class Formula

  def releases
    self.class.releases
  end

  class << self

    attr_reader :releases

    def release(r, &block)
      raise ":sha256 key not present in the release" unless r.has_key?(:sha256) or (type == :utility)
      @releases = [] if !@releases
      @releases << Release.new(r[:version], r[:crystax_version], r[:sha256])
    end
  end
end


class Utility < Formula
  def type
    :utility
  end
end


class Curl < Utility

  release version: '7.42.0', crystax_version: 1, sha256: { linux_x86_64:   '0'
                                                           linux_x86:      '0'
                                                           darwin_x86_64:  '0'
                                                           darwin_x86:     '0'
                                                           windows_x86_64: '0'
                                                           windows:        '0'
                                                         }

end

f = Curl.new
