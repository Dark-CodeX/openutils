pkgname="sstring"
pkgver="1.5.2"
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
  "a0907022c75909c759ac9a8363669cdbaeadb8a3b5677613f62b1d41c1f21d2d333a3ef401eea09ed4a9f67ab53a0e567d5bda593dc9d190a87b6f4cb65b6156"
  "1b89773b66db592ffea2218f2e42964653ccce7058226298aebc6c3e03a15b894db1c2c506c3ab36c63a4ad54d10f80a7a2d61e24da16af5901f1a45a757aef7"
  "c45ff39534123b58df6fb7ff14388c0a244b44a32dcf6b07831306ac54274c0aafda6e221572fa56e90d0b9ca441774e097b19bb893802d5ee3d7b1e880768fb"
  "443df0102045d99fe32c9e989140043ec5c8518a3891895c2302f40d042e2f70d4138fa0e584aa619d74a8431808063a570402a58b5603b7564fa64e45762605"
  "7aa5c43a3c165a64f6b8e34cba80a10bdefe9d3d691c514b206d324f86f9a22f311e0d81926be9218dc2e92da00e811694cd5eb3e81413606304fc4968d9f646")

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
