pkgname="sstring"
pkgver="17.3.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("52b1647f39c9a51e85926694580f73b19069f7e8cb181a43ee47d9d092e43575700e847235a50ab7ce2f0491c45fb0096c53a6d924fa513dd2a5b61ae8acaa6d" "a91111a4256943ec29361266e614b1f48c5984c2c048d334e53892c900ad2cdbc2f0cace8447511ef7caf335352920ebf02d23f68ca3f5536fc2ac5b11e07f84" "8e7c4d92aff206fa952399cd7c9c6bb3955998db0ec8e0070b85e25d8e2935daeffe5978b765612ecf456bc5e7f41672416af96b205c51bf28cd2cd5d1d00ba2")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
