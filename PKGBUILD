pkgname="sstring"
pkgver="49.2.0"
pkgrel="7"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.hh")

sha512sums=(
  "645e2cb4d28ca8b860815fdd01c128de9f60dfc00d5901c6aac0461ab6bea84018a0ca1366b095982c79076c3b69ec2d34b98a1564b13a801c2fc41ef57059b7"
  "c14f1225c132e65c94adc6129148480bb9d04d8ffabe3757070d9a596367548e8e413c12f73164f3f9de4ff60b3efe9fa7756881b77d1f713bb9b310e32ce44f"
  "b219f8eb081b51c8dd9a90044ab32bf82295a4765158250ee264b29823e40ee5ef4a82caae99690160ac2d80efc1a1607f16c2fdc5ecb3f0dadbf584615c9eea"
  "b785b20488162c0ad8bac79d0ed93984b30a1db886436c188f452ee4eebc3ef3e87618f85e6b584731d9a12d3e3472f67ca1c3b2171ea8f6c4aef2ceb70a9619"
  "6a3cf448165599b830c2b2ec2f2e3bcb61db2201dc689b32d4fd42391fcf548a0e110822f225f5e4b4bdfe665acf3fa8e8733630b1999733dfd3745b979a0436")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/sstring/sstring.hh"
  echo "Done!"
}
