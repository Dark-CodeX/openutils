pkgname="sstring"
pkgver="17.0.5"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("6920100f601ac4760274a0b9db1b8d36e50476ea011dc1d58623ad7e894e1918591329c95d32b23130ab18ace6dedb221c31d85f9d280d64dec6791e0187ac7d" "0edff1b0fd15eb770e2072dc9bb50bbef2d3c9b1acff383b17680a983ebef1492b10285cfc0d2d6e8b8507989546d51b375f9a9ab9a966dbb0d6698b590e0dfa" "e150b37e883f6a4ee1383495e4cf0a84908af6363dea500240dfb8ccf0bb52faab2a288c9344dbcc60a6e7c1f9f832237bf40127b310de345790f1e1257d9b70")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
